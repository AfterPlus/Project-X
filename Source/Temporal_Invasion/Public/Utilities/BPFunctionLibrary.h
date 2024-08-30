// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctionLibrary.generated.h"


class AMainPlayerController;
class AMainHUD;
class AMyCharacter;
class AMainGameModeBase;
class AGameStartMapModeBase;
class AGameStartHUD;
class AGameStartCharacter;
class AGameStartPlayerController;
/**
 * 
 */
UCLASS()
class TEMPORAL_INVASION_API UBPFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category="CPP | Utilities")
	static void CastToCore_Main(UObject* WorldContext, AMainGameModeBase*& AsMainGameMode,
		AMainPlayerController*& AsMainPlayerController, AMyCharacter*& AsMainPlayerCharacter,
		AMainHUD*& AsMainHUD);

	UFUNCTION(BlueprintCallable, Category="CPP | Utilities")
	static void CastToGameStartMap(UObject* WorldContext, AGameStartMapModeBase*& AsGameStartMapModeBase,
		AGameStartPlayerController*& AsGameStartPlayerController, AGameStartCharacter*& AsGameStartCharacter,
		AGameStartHUD*& AsGameStartHUD);
};
