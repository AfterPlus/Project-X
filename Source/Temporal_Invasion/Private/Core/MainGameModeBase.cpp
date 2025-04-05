// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/MainGameModeBase.h"
#include "Enemies/MasterEnemy.h"
#include "Utilities/EventsHolder.h"

AMainGameModeBase* AMainGameModeBase::Instance = nullptr ;

void AMainGameModeBase::Init()
{
	Instance = this;
	EventsHolder = NewObject<UEventsHolder>(this);
}

void AMainGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	Instance = this ;

	
	//EventsHolder->ini
}

AMainGameModeBase* AMainGameModeBase::GetInstance()
{
	
	return Instance ;
	
}

void AMainGameModeBase::SpawnEnemies()
{
	UWorld* World = GetWorld(); // Or pass this in
	if (!World) return;

	for (const FStageEnemyData& StageData : EnemyList)
	{
		for (const TSubclassOf<AMasterEnemy>& EnemyClass : StageData.EnemyTypes)
		{
			if (EnemyClass)
			{
				FVector SpawnLocation = FVector::ZeroVector; 
				FRotator SpawnRotation = FRotator::ZeroRotator;

				FActorSpawnParameters SpawnParams;
				SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

				AMasterEnemy* SpawnedEnemy = World->SpawnActor<AMasterEnemy>(EnemyClass, SpawnLocation, SpawnRotation, SpawnParams);

				if (SpawnedEnemy)
				{
					SpawnedEnemies.Add(SpawnedEnemy);
				}
			}
		}
	}
	
}



