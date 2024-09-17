// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UserWidgetBase.h"
#include "GameFramework/HUD.h"
#include "GameStartHUD.generated.h"

/**
 * 
 */
UCLASS()
class TEMPORAL_INVASION_API AGameStartHUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="MainMenu Widget")
	UUserWidgetBase* MainMenuBase;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="MainMenu Widget")
	UUserWidgetBase* MainMenu;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="MainMenu Widget")
	UUserWidgetBase* OptionsMenu;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="MainMenu Widget")
	UUserWidgetBase* ExitPrompt;
};
