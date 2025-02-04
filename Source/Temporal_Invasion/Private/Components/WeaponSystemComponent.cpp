// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/WeaponSystemComponent.h"
#include "MasterWeapon.h"
#include "GraphColor/Private/appconst.h"


// Sets default values for this component's properties
UWeaponSystemComponent::UWeaponSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWeaponSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UWeaponSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                           FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UWeaponSystemComponent::PickUpWeapon_Implementation(AMasterWeapon* Weapon)
{
	
}


bool UWeaponSystemComponent::CheckForWeaponSwap_Implementation(AMasterWeapon* Weapon)
{
	return bool();
}

void UWeaponSystemComponent::SwapWeapon_Implementation()
{
	
}



