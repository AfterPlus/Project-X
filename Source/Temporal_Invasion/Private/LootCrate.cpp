﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "LootCrate.h"


// Sets default values
ALootCrate::ALootCrate()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALootCrate::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALootCrate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALootCrate::InteractPressed_Implementation(AActor* Interact_Actor)
{
	IActorInterface::InteractPressed_Implementation(Interact_Actor);
}

void ALootCrate::OpenCrate_Implementation()
{
	
}

