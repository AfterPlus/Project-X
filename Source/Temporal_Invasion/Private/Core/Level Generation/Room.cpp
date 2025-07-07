// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Level Generation/Room.h"
#include "Components/BoxComponent.h"


// Sets default values
ARoom::ARoom()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	
	Props = CreateDefaultSubobject<USceneComponent>(TEXT("Props"));
	Props->SetupAttachment(RootComponent);

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxComp->SetupAttachment(RootComponent);
	
	PhysicsProps = CreateDefaultSubobject<USceneComponent>(TEXT("PhysicsProps"));
	PhysicsProps->SetupAttachment(Props);

	Doors = CreateDefaultSubobject<USceneComponent>(TEXT("Doors"));
	Doors->SetupAttachment(RootComponent);
	
	Exit = CreateDefaultSubobject<USceneComponent>(TEXT("Exit"));
	Exit->SetupAttachment(RootComponent);

	LineTracePoints = CreateDefaultSubobject<USceneComponent>(TEXT("LineTracePoints"));
	LineTracePoints->SetupAttachment(RootComponent);

	EnemiesSpawnPoints = CreateDefaultSubobject<USceneComponent>(TEXT("EnemiesSpawnPoints"));
	EnemiesSpawnPoints->SetupAttachment(RootComponent);

	NavLinkLocation = CreateDefaultSubobject<USceneComponent>(TEXT("NavLinkLocation"));
	NavLinkLocation->SetupAttachment(RootComponent);	
	
}

// Called when the game starts or when spawned
void ARoom::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool ARoom::CheckForRoomOverlap_Implementation()
{
	return false;
}

void ARoom::SimulatePhysics_Implementation(bool Simulate)
{
	
}



