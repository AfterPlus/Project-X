// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ActorInterface.generated.h"


class AMasterWeapon;

// This class does not need to be modified.
UINTERFACE()
class UActorInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TEMPORAL_INVASION_API IActorInterface
{
	GENERATED_BODY()

public:
	/** Interact object when overlap */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void InteractPressed(AActor* Interact_Actor);

	/** Interact object when overlap */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ActorOnInitialize(AActor* Interact_Actor);

	/** Interact object when overlap */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void StartInteract(AActor* Interact_Actor);

	/** Interact object when overlap */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void StopInteract(AActor* Interact_Actor);

	/** Interface to delete the weapon class */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void DeleteClass();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool CanDisplaySkill();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void UpdateSkill();

#pragma region AI

	////////////////////////////////////////////////////////
	/** All AI actions */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void CheckForEnemiesRange(bool bIsInRange);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool CanPerformSpecialAttack();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PlaySpecialAttack();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void EnemyFire();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ApplyDamageToEnemy(float Damage);
	
#pragma endregion


#pragma region Weapon
	//////////////////////////////////////////////////////
	/** All weapon actions */
	/** Fire the in hand weapon */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void StartWeaponFire();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void AddGrenadeClass(TSubclassOf<AMasterGrenade> GrenadeClass) ;

	/** Fire the in hand weapon */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void StopWeaponFire();

	/** Weapon Reload */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void WeaponReload();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SpawnRoom();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void DestroyRoom();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void CachedImpactPoint(FVector& Impulse, FString& BoneName, AMasterWeapon* Weapon, FHitResult HitResult);

#pragma endregion
};
