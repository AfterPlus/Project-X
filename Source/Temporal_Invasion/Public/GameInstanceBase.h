// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Utilities/StructsLibrary.h"
#include "GameInstanceBase.generated.h"

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
};
