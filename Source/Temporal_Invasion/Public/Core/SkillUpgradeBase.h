// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Utilities/ActorInterface.h"

#include "SkillUpgradeBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TEMPORAL_INVASION_API USkillUpgradeBase : public UObject,
	public IActorInterface
{
	GENERATED_BODY()

	public:
	virtual bool CanDisplaySkill () ;

	virtual void DisplaySkill();
	
};
