﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Level Generation/Door.h"

#include "Core/Level Generation/LevelGenerator.h"


// Sets default values
ADoor::ADoor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bCanOpen = true;
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADoor::SpawnAlley_Implementation()
{
	if (LevelGenerator)
		
	for (int32 i = 0; i < LevelGenerator->SpawnedAlley.Num(); i++)
	{
		const int Random = FMath::RandRange(0, LevelGenerator->SpawnedAlley.Num() - 1);
		CurrentAlley = LevelGenerator->SpawnedAlley[Random];

		if (!CurrentAlley)
			return;

		CurrentAlley->SetActorLocation(GetActorLocation()+FVector(0,0,500));
		CurrentAlley->SetActorRotation(GetActorRotation());
		if (CurrentAlley->CheckForAlleyOverlap())
		{
			CurrentAlley->SetActorLocation(FVector(0,0,-5000));
			bCanOpen = false;
		}
		else
		{
			break;
		}
		
	}
	if (bCanOpen)
	{
		CurrentAlley->SetActorLocation(GetActorLocation());
		// Add delay
		CurrentAlley->SimulatePhysics(true);
		CurrentAlley->SpawnRoom();
		LevelGenerator->SpawnedAlley.Remove(CurrentAlley);
		bCanOpen = true ;
	}
	

}

