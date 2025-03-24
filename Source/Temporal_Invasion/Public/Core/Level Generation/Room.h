// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Utilities/ActorInterface.h"
#include "Room.generated.h"

class UBoxComponent;

UCLASS()
class TEMPORAL_INVASION_API ARoom : public AActor,
	public IActorInterface

{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARoom();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component")
	USceneComponent* Props ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component")
	USceneComponent* PhysicsProps ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component")
	UBoxComponent* BoxComp;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component")
	USceneComponent* Doors ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component")
	USceneComponent* EnemiesSpawnPoints ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component")
	USceneComponent* Exit ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component")
	USceneComponent* LineTracePoints ; 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool CheckForRoomOverlap();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SimulatePhysics(bool Simulate);
	
};
