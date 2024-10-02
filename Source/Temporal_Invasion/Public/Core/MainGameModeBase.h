// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Utilities/BPFunctionLibrary.h"
#include "GameFramework/GameModeBase.h"

#include "MainGameModeBase.generated.h"


class UDelegates;
class UUserWidget;
UCLASS()
class TEMPORAL_INVASION_API AMainGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	static AMainGameModeBase* GetInstance();

protected:
	virtual void BeginPlay() override;

private:
	static AMainGameModeBase* Instance;
	
};
