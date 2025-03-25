// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemies/MasterEnemy.h"

#include "LevelManager.generated.h"

UCLASS()
class TEMPORAL_INVASION_API ALevelManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALevelManager();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<TSubclassOf<AMasterEnemy>> Enemies ;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	static ALevelManager* Instance;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Level Manager"))
	static ALevelManager* GetInstance();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SpawnEnemies();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void InitDoor();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void DeployEnemies(FVector SpawnLocation);

	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void EnemyDefeated();
};
