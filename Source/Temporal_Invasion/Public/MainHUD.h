// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorInterface.h"
#include "GameFramework/HUD.h"
#include "MainHUD.generated.h"

/**
 * 
 */
UCLASS()
class TEMPORAL_INVASION_API AMainHUD : public AHUD,
	public IActorInterface
{
	GENERATED_BODY()

	virtual void ActorOnInitialize_Implementation(AActor* Interact_Actor) override;
};
