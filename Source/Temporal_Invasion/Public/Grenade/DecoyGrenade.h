﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MasterGrenade.h"
#include "DecoyGrenade.generated.h"

UCLASS()
class TEMPORAL_INVASION_API ADecoyGrenade : public AMasterGrenade
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADecoyGrenade();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};