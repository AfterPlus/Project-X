// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "3dMiniMap/MiniMap.h"
#include "GameFramework/GameModeBase.h"

#include "MainGameModeBase.generated.h"


class UEventsHolder;
class UDelegates;
class UUserWidget;
UCLASS()
class TEMPORAL_INVASION_API AMainGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	static AMainGameModeBase* GetInstance();
		
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere)
	AMiniMap* MiniMap;

	UPROPERTY(BlueprintReadOnly)
	UEventsHolder* EventsHolder;

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Classes")
	TSubclassOf<UEventsHolder> EventHolderClass;

	UFUNCTION(BlueprintCallable)
	void Init();
	
protected:
	virtual void BeginPlay() override;
	
	static AMainGameModeBase* Instance;
	
};
