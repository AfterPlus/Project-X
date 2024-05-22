// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponSystemComponent.generated.h"

class AMasterWeapon;
UCLASS(Blueprintable, meta=(BlueprintSpawnableComponent))
class TEMPORAL_INVASION_API UWeaponSystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UWeaponSystemComponent();

	/** The weapon that would be in the players range to interact */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	AMasterWeapon* InteractingWeapon;

	/** The weapon that is in the players hand */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	AMasterWeapon* InHandWeapon;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	/** Pick up a weapon if the inventory slot is not empty */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PickUpWeapon(AMasterWeapon* Weapon);

	/** Swap with the in hand weapon and equip the interacting weapon */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SwapWeapon();

	/** Check if the in hand weapon and interacting weapon are the same */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool CheckForWeaponSwap(AMasterWeapon* Weapon);
};
