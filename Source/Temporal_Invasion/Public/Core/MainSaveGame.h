// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MasterWeapon.h"
#include "GameFramework/SaveGame.h"
#include "Utilities/StructsLibrary.h"
#include "MainSaveGame.generated.h"

class AAlley;
class ARoom;
/**
 * 
 */

USTRUCT(BlueprintType)
struct FAlleySaveData
{
	GENERATED_BODY()

	// The class of the actor (so we know what to respawn)
	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<AAlley> Alley ;

	// Transform (location, rotation, scale)
	UPROPERTY(BlueprintReadWrite)
	FTransform AlleyTransform ;

	UPROPERTY(BlueprintReadWrite)
	bool bIsAtLocation ;
};


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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rooms")
	TArray<ARoom*> AllRooms ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rooms")
	TArray<FAlleySaveData> AlleyStruct ;

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

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void AddAlley(FAlleySaveData ActorSaveData);
	
};
