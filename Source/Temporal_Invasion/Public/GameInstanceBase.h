// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Level Generation/Room.h"
#include "Engine/GameInstance.h"
#include "Utilities/StructsLibrary.h"
#include "GameInstanceBase.generated.h"

class AAlley;
/**
 * 
 */
UCLASS()
class TEMPORAL_INVASION_API UGameInstanceBase : public UGameInstance
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	FCharactersStats CharactersStats;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Variables")
	TMap<FString, FUpgrades> CachedSkill;

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Variables")
	TArray<FUpgrades> SkillUpgrade;

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Variables")
	TArray<FUpgrades> CachedSkillUpgrade;

public:

	virtual void Init() override;
	
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get Game Instance"))
	static UGameInstanceBase* GetInstance();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void LoadSkills();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void UpgradeSkillType(ESkillType SkillType);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SaveCharacterStats(FCharactersStats Stats);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SavePlayer(FPlayerSaveData SaveData);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SavePlayerInHandWeapon(AMasterWeapon* InHandWeapon);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SaveWeaponInfo(int CurrentAmmo, int MaxAmmo);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SaveAlley(TSubclassOf<AAlley> Alley, FTransform Transform, bool bIsAtLocation);
	
protected:
	static UGameInstanceBase* Instance;
	
};
