// Fill out your copyright notice in the Description page of Project Settings.


#include "MasterWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Utilities/EnumLibrary.h"
#include "Core/MyCharacter.h"

// Sets default values
AMasterWeapon::AMasterWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(RootComponent);

	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunMesh"));
	SkeletalMeshComponent->SetupAttachment(RootComponent);
	RootComponent = SkeletalMeshComponent;
	

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetupAttachment(SkeletalMeshComponent);
	SphereComponent->SetSphereRadius(100.f);
	
}

// Called when the game starts or when spawned
void AMasterWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMasterWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMasterWeapon::StartWeaponFire_Implementation()
{
	
}

void AMasterWeapon::StopWeaponFire_Implementation()
{
	
}

void AMasterWeapon::WeaponReload_Implementation()
{
	
}

void AMasterWeapon::AutoReload_Implementation()
{
	
}

void AMasterWeapon::CancelReload_Implementation()
{
	
}

void AMasterWeapon::UpdateCrosshair_Implementation(EWeaponType WeaponType)
{
	
}

void AMasterWeapon::UpdateWeaponState_Implementation(EWeaponState WeaponState)
{
	
}

bool AMasterWeapon::BeginLineTraceToDeductWeapon_Implementation()
{
	return false;
}



