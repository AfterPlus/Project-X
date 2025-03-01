// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Level Generation/Room.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	TArray<TSubclassOf<ARoom>> Rooms;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	TArray<TSubclassOf<ARoom>> Alleys;

public:

	virtual void Init() override;
	
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get Game Instance"))
	static UGameInstanceBase* GetInstance();
	
protected:
	static UGameInstanceBase* Instance;
	
};
