// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Alley.h"
#include "Room.h"
#include "GameFramework/Actor.h"
#include "LevelGenerator.generated.h"

class AAlley;
class ARoom;

UCLASS()
class TEMPORAL_INVASION_API ALevelGenerator : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALevelGenerator();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	TArray<TSubclassOf<AAlley>> Alleys;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	TArray<AAlley*> SpawnedAlley;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	TArray<TSubclassOf<ARoom>> Rooms;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	TArray<ARoom*> SpawnedRooms;
	
	
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get Level Generator"))
	static ALevelGenerator* GetInstance();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	static ALevelGenerator* Instance;
};
