// Fill out your copyright notice in the Description page of Project Settings.


#include "Utilities/BPFunctionLibrary.h"

#include "Core/MainGameModeBase.h"
#include "Core/MainPlayerController.h"
#include "Core/MyCharacter.h"
#include "Core/MainHUD.h"
#include "GameStartMap/GameStartCharacter.h"
#include "GameStartMap/GameStartHUD.h"
#include "GameStartMap/GameStartMapModeBase.h"
#include "GameStartMap/GameStartPlayerController.h"
#include "Kismet/GameplayStatics.h"


void UBPFunctionLibrary::CastToCore_Main(UObject* WorldContext, AMainGameModeBase*& AsMainGameMode,
                                         AMainPlayerController*& AsMainPlayerController, AMyCharacter*& AsMainPlayerCharacter, AMainHUD*& AsMainHUD)
{
	AsMainGameMode = Cast<AMainGameModeBase>(UGameplayStatics::GetGameMode(WorldContext));
	AsMainPlayerController = Cast<AMainPlayerController>(UGameplayStatics::GetPlayerController(AsMainGameMode, 0));
	AsMainPlayerCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(AsMainGameMode, 0));
	AsMainHUD = Cast<AMainHUD>(AsMainPlayerController->GetHUD());
}

void UBPFunctionLibrary::CastToGameStartMap(UObject* WorldContext, AGameStartMapModeBase*& AsGameStartMapModeBase,
	AGameStartPlayerController*& AsGameStartPlayerController, AGameStartCharacter*& AsGameStartCharacter,
	AGameStartHUD*& AsGameStartHUD)
{
	AsGameStartMapModeBase = Cast<AGameStartMapModeBase>(UGameplayStatics::GetGameMode(WorldContext));
	AsGameStartPlayerController = Cast<AGameStartPlayerController>(UGameplayStatics::GetPlayerController(AsGameStartMapModeBase, 0));
	AsGameStartCharacter = Cast<AGameStartCharacter>(UGameplayStatics::GetPlayerCharacter(AsGameStartMapModeBase, 0));
	AsGameStartHUD = Cast<AGameStartHUD>(AsGameStartPlayerController->GetHUD());
}
