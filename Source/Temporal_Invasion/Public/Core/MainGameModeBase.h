// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Utilities/EnumLibrary.h"
#include "3dMiniMap/MiniMap.h"
#include "GameFramework/GameModeBase.h"
#include "Utilities/StructsLibrary.h"
#include "MainGameModeBase.generated.h"

class ARoom;
class AAlley;
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

	UPROPERTY(BlueprintReadOnly)
	UEventsHolder* EventsHolder;

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Classes")
	TSubclassOf<UEventsHolder> EventHolderClass;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	ARoom* CurrentRoom = nullptr;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	TArray<TSubclassOf<AAlley>> Alleys;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	TArray<AAlley*> SpawnedAlley;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	TArray<TSubclassOf<ARoom>> Rooms;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	TArray<ARoom*> SpawnedRooms;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	TArray<FStageEnemyData> EnemyList ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	TArray<AMasterEnemy*> SpawnedEnemies;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	int CurrentLevel = -1 ;
	
protected:
	virtual void BeginPlay() override;
	
	static AMainGameModeBase* Instance;

public:
	
	UFUNCTION(BlueprintCallable)
	void Init();

	UFUNCTION(BlueprintCallable)
	void SpawnEnemies();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void DisplaySkillType(ESkillType SkillType);


};
