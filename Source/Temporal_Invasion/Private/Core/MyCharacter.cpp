// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/MyCharacter.h"
#include "Utilities/BPFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "MasterWeapon.h"
#include "MasterGrenade.h"
#include "Components/AudioComponent.h"
#include "Components/GrappleComponent.h"
#include "Components/WidgetComponent.h"
#include "Core/MainGameModeBase.h"
#include "Utilities/EventsHolder.h"
#include "WorldPartition/HLOD/DestructibleHLODComponent.h"

AMyCharacter* AMyCharacter::Instance = nullptr ;

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunMesh"));
	//GunMesh->SetupAttachment(GetMesh(),TEXT("GunSocket"));

	
	//GunHolder = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunHolder"));
	//GunHolder->SetupAttachment(GetMesh(),TEXT("GunSocket"));

	InteractWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("InteractWidget"));
	isWeaponWidgetActive = true ;

	EnemyRadius = CreateDefaultSubobject<USphereComponent>(TEXT("EnemyRadius"));
	EnemyRadius->SetupAttachment(RootComponent);
	EnemyRadius->InitSphereRadius(100.0f);
	EnemyRadius->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	EnemyRadius->SetCollisionResponseToAllChannels(ECR_Overlap);
	

	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent"));
	AudioComponent->SetupAttachment(RootComponent);
	//AudioComponent->bAutoActivate = false;
	
}



// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	GameInstance = Cast<UGameInstanceBase>(GetGameInstance());
	
	CastToCoreMain();

	Instance = this ;

	GrappleHook = nullptr;

	PlayerController = GetWorld()->GetFirstPlayerController();

	UpdateCharacterStat();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	LineTraceForGrappleHook();
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyCharacter::AddGrenadeClass_Implementation(TSubclassOf<AMasterGrenade> GrenadeClass)
{
	IActorInterface::AddGrenadeClass_Implementation(GrenadeClass);
	AllGrenades.Add(GrenadeClass);
}

AMyCharacter* AMyCharacter::GetInstance()
{
	return Instance ;
}

void AMyCharacter::UpdateCharacterStat_Implementation()
{
	if (GameInstance)
	{
		CharactersStats = GameInstance->CharactersStats ;
		DashCount = CharactersStats.MaxDashCount ;
		GrappleCount = CharactersStats.MaxGrappleCount ;
		GrenadeCount = CharactersStats.MaxGrenadeCount ;
	}
}

void AMyCharacter::LineTraceForGrappleHook_Implementation()
{
	if (!PlayerController) return;

	int32 ViewportSizeX, ViewportSizeY;
	PlayerController->GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenCenter(ViewportSizeX * 0.5f, ViewportSizeY * 0.5f);


	FVector WorldLocation, WorldDirection;
	if (!PlayerController->DeprojectScreenPositionToWorld(ScreenCenter.X, ScreenCenter.Y, WorldLocation, WorldDirection))
	{
		return;
	}

	// Line trace Start, end and forward vector 
	FVector Start = WorldLocation;
	FVector End = Start + (WorldDirection * 1000.0f);
	FVector ForwardVector = GetActorForwardVector();
	 

	FHitResult HitResult;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this); // Ignore self
	
	if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_GameTraceChannel2, QueryParams))
	{
		AActor* HitActor = HitResult.GetActor();

		if (HitActor && HitActor->FindComponentByClass<UGrappleComponent>())
		{
			// Call function on newly hit actor
			HitActor->FindComponentByClass<UGrappleComponent>()->ShowMarker();

			// If the hit actor is different from the previously hit actor, notify the previous one
			if (GrappleHook && GrappleHook != HitActor)
			{
				GrappleHook->FindComponentByClass<UGrappleComponent>()->HideMarker();
			}

			// Update previously hit actor
			GrappleHook = HitActor;
		}
	}
	else
	{
		// If no actor is hit and there was a previously hit actor, trigger Hide event
		if (GrappleHook)
		{
			GrappleHook->FindComponentByClass<UGrappleComponent>()->HideMarker();
			GrappleHook = nullptr; // Reset
		}
	}
}

void AMyCharacter::UpdateGrappleCount_Implementation(int Value)
{
	GrappleCount = GrappleCount + Value ;
	AMainGameModeBase::GetInstance()->EventsHolder->Grapple.Broadcast(true);
}

void AMyCharacter::UpdateDashCount_Implementation(int Value)
{
	DashCount = DashCount + Value ;
	AMainGameModeBase::GetInstance()->EventsHolder->Dash.Broadcast(true);
}

void AMyCharacter::UpdateGrenadeCount_Implementation(int Value)
{
	GrenadeCount = GrenadeCount + Value ;
	AMainGameModeBase::GetInstance()->EventsHolder->GrenadeThrow.Broadcast();
}

bool AMyCharacter::Dash_Implementation(float DashDistance,float ForwardInput, float RightInput)
{
	if (DashCount > 0 )
	{
		bIsDashing = true;
	
		// Calculate dash direction
		FVector Forward = GetActorForwardVector();  // Default dash direction
		FVector Right = GetActorRightVector();

		FVector DashDirection;

		if (ForwardInput == 0.0f && RightInput == 0.0f)
		{
			// No input: Dash forward
			DashDirection = Forward;
			DashDirection = DashDirection * FVector(1.0f, 1.0f, 0.0f);
		}
		else
		{
			// Use input-based direction
			DashDirection = (Forward * ForwardInput + Right * RightInput).GetSafeNormal();
			DashDirection = DashDirection * FVector(1.0f, 1.0f, 0.0f);
		}
		// Launch character
		LaunchCharacter(DashDirection * DashDistance, true, true);
		
		AudioComponent->SetSound(DashSoundCue);
		AudioComponent->Play();
		
		DashCount -- ;
		
		AMainGameModeBase::GetInstance()->EventsHolder->Dash.Broadcast(false);

		return true;
	}
	
	return false;
}


void AMyCharacter::LineTraceForLootCrate_Implementation()
{
	
}

void AMyCharacter::CastToCoreMain_Implementation()
{
	//AMyCharacter* AsMyCharacter;
	//UBPFunctionLibrary::CastToCore_Main(GetWorld(),AsMainGameMode,AsMainPlayerController,AsMyCharacter,AsMainHUD);
}

bool AMyCharacter::GetLookInputVars_Implementation(FRotator CamRotPrev)
{
	return false ;
}

void AMyCharacter::GetVelocityVar_Implementation()
{
	
}

void AMyCharacter::Dip_Implementation(float Speed, float Strength)
{
	
}


void AMyCharacter::LandingDip_Implementation()
{
	
}

void AMyCharacter::CoyoteTimePasses_Implementation()
{
	
}

bool AMyCharacter::CheckCanStand_Implementation()
{
	return false;
}

void AMyCharacter::EquipWeapon_Implementation(int Index)
{
	
}

void AMyCharacter::SpawnWeapon_Implementation(TSubclassOf<AMasterWeapon> WeaponClass)
{
	
}

void AMyCharacter::SwitchWeapon_Implementation(int Index)
{
	
}


void AMyCharacter::EquipWeaponOnStart_Implementation()
{
	
}








