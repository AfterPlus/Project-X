// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Level Generation/Alley.h"


// Sets default values
AAlley::AAlley()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	
	Props = CreateDefaultSubobject<USceneComponent>(TEXT("Props"));
	Props->SetupAttachment(RootComponent);

	PhysicsProps = CreateDefaultSubobject<USceneComponent>(TEXT("PhysicsProps"));
	PhysicsProps->SetupAttachment(Props);
	
	Exit = CreateDefaultSubobject<USceneComponent>(TEXT("Exit"));
	Exit->SetupAttachment(RootComponent);

	LineTracePoints = CreateDefaultSubobject<USceneComponent>(TEXT("LineTracePoints"));
	LineTracePoints->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void AAlley::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAlley::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AAlley::CheckForAlleyOverlap_Implementation()
{
	return false;
}

void AAlley::SimulatePhysics_Implementation(bool Simulate)
{
	
}



