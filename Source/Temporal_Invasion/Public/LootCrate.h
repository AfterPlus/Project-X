﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Utilities/ActorInterface.h"
#include "LootCrate.generated.h"

UCLASS()
class TEMPORAL_INVASION_API ALootCrate : public AActor,
	public IActorInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALootCrate();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bIsOpen;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void InteractPressed_Implementation(AActor* Interact_Actor) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OpenCrate();
};
