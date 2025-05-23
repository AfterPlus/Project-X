﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/LevelManager.h"

#include "Core/MainGameModeBase.h"
#include "Core/MainPlayerController.h"
#include "Core/Level Generation/Door.h"
#include "Core/Level Generation/Room.h"
#include "Kismet/GameplayStatics.h"

ALevelManager* ALevelManager::Instance = nullptr ;

// Sets default values
ALevelManager::ALevelManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALevelManager::BeginPlay()
{
	Super::BeginPlay();
	Instance = this;
}

// Called every frame
void ALevelManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

ALevelManager* ALevelManager::GetInstance()
{
	return Instance;
}

void ALevelManager::EnemyDefeated_Implementation()
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	AMainPlayerController* MainController = Cast<AMainPlayerController>(PlayerController);

	if (EnemyRemaining > 0)
	{
		EnemyRemaining--;
		if ( EnemyRemaining == 0 )
		{
			TArray<ADoor*> Doors = AMainGameModeBase::GetInstance()->CurrentRoom->SpawnedDoors;
			for (auto Door : Doors)
			{
				Door->Init(true);
				if (MainController)
					MainController->ShowUpgradeWidget();
			}
		}
	}
}

void ALevelManager::DeployEnemies_Implementation(FVector SpawnLocation)
{
	
}

void ALevelManager::InitDoor_Implementation()
{
	
}

void ALevelManager::SpawnEnemies_Implementation()
{
	
}

