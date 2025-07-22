// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MasterWeapon.h"
#include "GameFramework/SaveGame.h"
#include "Utilities/StructsLibrary.h"
#include "MainSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class TEMPORAL_INVASION_API UMainSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	FCharactersStats CharactersStats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	FVector CharactersLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	FPlayerSaveData PlayerSaveData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	AMasterWeapon* InHandWeapon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	TArray<AMasterWeapon*> AllWeapons ;

	/** To check if the save file is already saved */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	bool bHasInitialized = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Info")
	int CurrentAmmo ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Info")
	int MaxAmmo ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Info")
	TMap<FString, int32> WeaponAmmoMap;


	
};
