// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/MyCharacter.h"
#include "Utilities/BPFunctionLibrary.h"
#include "MasterWeapon.h"
#include "Components/WidgetComponent.h"


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
	
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	CastToCoreMain();
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








