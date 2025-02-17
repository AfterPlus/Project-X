// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "SkillUpgradeBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TEMPORAL_INVASION_API USkillUpgradeBase : public UObject
{
	GENERATED_BODY()

	public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool CanBeDisplayed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void UpdateSkill();
};
