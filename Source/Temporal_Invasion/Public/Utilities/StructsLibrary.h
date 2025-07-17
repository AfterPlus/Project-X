// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnumLibrary.h"
#include "StructsLibrary.generated.h"

class AMasterEnemy;
class USkillUpgradeBase;

USTRUCT(BlueprintType)
struct FUpgrades : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	FString UpgradeName ;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	UTexture2D* Icon ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	FString Description ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	TEnumAsByte<ESkillType> SkillType = ESkillType_None ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	TEnumAsByte<ESkillRarity> SkillRarity  = ESkillRarity_None;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	TSubclassOf<USkillUpgradeBase> SkillUpgradeClass ;
	
};

USTRUCT(BlueprintType)
struct FStageEnemyData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	TArray<TSubclassOf<AMasterEnemy>> EnemyTypes ;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 Level ;
	
};

USTRUCT(BlueprintType)
struct FCharactersStats 
{
	GENERATED_BODY()
	
	// Health and Armor stat
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float MaxHealth = 0.0f ;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float MaxArmor = 0.0f ;
	
	// Weapon
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon")
	int InventorySlots = 3;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon", meta = (ClampMin = "0.1", ClampMax = "2.0", UIMin = "0.1", UIMax = "2.0"))
	float Recoil = 0 ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon", meta = (ClampMin = "0.1", ClampMax = "2.0", UIMin = "0.1", UIMax = "2.0"))
	float Spray = 0 ;
	
	// Abilities 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
	int MaxDashCount = 2 ;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Abilities")
	int MaxGrappleCount = 2 ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Abilities")
	int MaxGrenadeCount = 2 ;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Abilities", meta = (ClampMin = "0.1", ClampMax = "1.0", UIMin = "0.1", UIMax = "1.0"))		// Keep the value form 0.1 to 1 
	float DashRechargeTimer = 0.5f ;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Abilities", meta = (ClampMin = "0.4", ClampMax = "0.6", UIMin = "0.4", UIMax = "0.6"))		// Keep the value form 0.4 to 0.6
	float GrappleRechargeTimer = 0.5f ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Abilities", meta = (ClampMin = "0.1", ClampMax = "1.0", UIMin = "0.1", UIMax = "1.0"))		
	float GrenadeRechargeTimer = 0.5f ;
	
};