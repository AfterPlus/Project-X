// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Room.h"

#include "Alley.generated.h"

class ALevelGenerator;

UCLASS()
class TEMPORAL_INVASION_API AAlley : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAlley();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component")
	USceneComponent* Props ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component")
	USceneComponent* PhysicsProps ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component")
	USceneComponent* Exit ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component")
	USceneComponent* LineTracePoints ;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Variables")
	ARoom* CurrentRoom = nullptr ;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Variables",  meta = (ExposeOnSpawn = "true"))
	ALevelGenerator* LevelGenerator ;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SpawnRoom();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool CheckForAlleyOverlap();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SimulatePhysics(bool Simulate);
};
