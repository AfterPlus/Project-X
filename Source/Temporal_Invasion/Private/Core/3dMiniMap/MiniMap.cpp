// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/3dMiniMap/MiniMap.h"

AMiniMap* AMiniMap::Instance = nullptr;

// Sets default values
AMiniMap::AMiniMap()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MiniMapMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MiniMapComponent"));
	MiniMapMesh->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void AMiniMap::BeginPlay()
{
	Super::BeginPlay();
	Instance = this;
}

AMiniMap* AMiniMap::GetInstance()
{
	return Instance;
}

// Called every frame
void AMiniMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

