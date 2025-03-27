// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Level Generation/Door.h"

#include "Core/MainGameModeBase.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include "Core/Level Generation/LevelGenerator.h"
#include "Utilities/EventsHolder.h"


// Sets default values
ADoor::ADoor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	
	TextRender = CreateDefaultSubobject<UTextRenderComponent>("TextRender");
	TextRender->SetupAttachment(RootComponent);

	
	TextRender->SetText(FText::FromString(TEXT(" Test ")));
	
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

void ADoor::TryPlaceRandomAlley_Implementation()
{
	TextRender->SetText(FText::FromString(TEXT("  ")));
	
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
			bCanOpen = true;
			break;
		}
	}
	
	TextRender->SetText(FText::FromString(TEXT("Open")));

}

void ADoor::SpawnAlley_Implementation()
{
	if (bCanOpen)
	{
		CurrentAlley->SetActorLocation(GetActorLocation());
		
		// Add delay
		FTimerHandle Delay ;
		GetWorld()->GetTimerManager().SetTimer(Delay, this, &ADoor::SpawnNextRoom_Implementation, 0.2f, false);
		bCanOpen = true ;

		AMainGameModeBase::GetInstance()->EventsHolder->AreaCleared.Broadcast();
	}
}

void ADoor::SpawnNextRoom_Implementation()
{
	CurrentAlley->SimulatePhysics(true);
	CurrentAlley->SpawnRoom();
	LevelGenerator->SpawnedAlley.Remove(CurrentAlley);
}





