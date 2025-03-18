// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Level Generation/LevelGenerator.h"

ALevelGenerator* ALevelGenerator::Instance = nullptr ;

// Sets default values
ALevelGenerator::ALevelGenerator()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

ALevelGenerator* ALevelGenerator::GetInstance()
{
	return Instance;
}

// Called when the game starts or when spawned
void ALevelGenerator::BeginPlay()
{
	Super::BeginPlay();
	Instance = this;
}

// Called every frame
void ALevelGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

