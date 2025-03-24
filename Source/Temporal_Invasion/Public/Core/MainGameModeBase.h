// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Utilities/EnumLibrary.h"
#include "3dMiniMap/MiniMap.h"
#include "GameFramework/GameModeBase.h"
#include "Level Generation/Room.h"
#include "Utilities/StructsLibrary.h"
#include "MainGameModeBase.generated.h"

class AMiniMapPawn;
class UEventsHolder;
class UDelegates;
class UUserWidget;
UCLASS()
class TEMPORAL_INVASION_API AMainGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get Main Game Mode"))
	static AMainGameModeBase* GetInstance();
		
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere)
	AMiniMap* MiniMap;

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere)
	AMiniMapPawn* MiniMapPawn;

	UPROPERTY(BlueprintReadOnly)
	UEventsHolder* EventsHolder;

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Classes")
	TSubclassOf<UEventsHolder> EventHolderClass;

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Classes")
	TMap<FString, FUpgrades> CachedSkill;

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Classes")
	TArray<FUpgrades> SkillUpgrade;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	ARoom* CurrentRoom = nullptr;

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Classes")
	TArray<FUpgrades> CachedSkillUpgrade;
	
protected:
	virtual void BeginPlay() override;
	
	static AMainGameModeBase* Instance;

public:
	UFUNCTION(BlueprintCallable)
	void Init();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void LoadSkills();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void UpgradeSkillType(ESkillType SkillType);
};
