// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelGenerator.generated.h"

UCLASS()
class TEMPORAL_INVASION_API ALevelGenerator : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALevelGenerator();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	USceneComponent* ExitPoint ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	TArray<USceneComponent*> ExitsPoints ; 
	
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
