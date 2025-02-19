// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnumLibrary.h"
#include "StructsLibrary.generated.h"

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
	TEnumAsByte<ESkillType> SkillType ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	TEnumAsByte<ESkillRarity> SkillRarity  ;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	TSubclassOf<USkillUpgradeBase> SkillUpgradeClass ;
	
};