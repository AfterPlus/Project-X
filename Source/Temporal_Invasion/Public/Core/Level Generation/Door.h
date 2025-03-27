// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Alley.h"
#include "Components/TextRenderComponent.h"
#include "Core/MainGameModeBase.h"

#include "Door.generated.h"

UCLASS()
class TEMPORAL_INVASION_API ADoor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADoor();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component")
	UTextRenderComponent* TextRender;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	AMainGameModeBase* MainGameMode;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	AAlley* CurrentAlley = nullptr ;

	// To Do 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	bool bIsDoorSpawned ;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	bool bCanOpen ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	ALevelGenerator* LevelGenerator = nullptr;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void Init(bool Condition);
	
	// First draw a line trace 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void TryPlaceRandomAlley();

	// Set the room to the doors location
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SpawnAlley();

	// Spawn the next room 
	UFUNCTION(BlueprintNativeEvent)
	void SpawnNextRoom();

	// Called when E is pressed
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OpenDoor();
};



