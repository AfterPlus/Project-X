// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/MyCharacter.h"
#include "Utilities/BPFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "MasterWeapon.h"
#include "MasterGrenade.h"
#include "Components/AudioComponent.h"
#include "Components/WidgetComponent.h"
#include "Core/MainGameModeBase.h"
#include "Utilities/EventsHolder.h"

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

	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent"));
	AudioComponent->SetupAttachment(RootComponent);
	//AudioComponent->bAutoActivate = false;
	
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	CastToCoreMain();

	Instance = this ;
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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

void AMyCharacter::UpdateGrappleCount_Implementation(int Value)
{
	GrappleCount = GrappleCount + Value ;
	AMainGameModeBase::GetInstance()->EventsHolder->Dash.Broadcast(true);
}

void AMyCharacter::UpdateDashCount_Implementation(int Value)
{
	DashCount = DashCount + Value ;
	AMainGameModeBase::GetInstance()->EventsHolder->Dash.Broadcast(true);
}

bool AMyCharacter::Dash_Implementation(float DashDistance,float ForwardInput, float RightInput)
{
	if (DashCount > 0 && !bIsCrouching)
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
		}
		else
		{
			// Use input-based direction
			DashDirection = (Forward * ForwardInput + Right * RightInput).GetSafeNormal();
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








