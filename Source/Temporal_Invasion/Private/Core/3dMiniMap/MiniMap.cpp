// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/3dMiniMap/MiniMap.h"

#include "Core/MainGameModeBase.h"
#include "Utilities/EventsHolder.h"

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

	MiniMapMarkers.Add(MiniMapMesh);
	//MainGameModeBase->EventsHolder->UpdateMiniMapMarkerReq.AddDynamic(this,&AMiniMap::AddMiniMapMarker);
}

void AMiniMap::Init()
{
	MainGameModeBase = AMainGameModeBase::GetInstance();
}

AMiniMap* AMiniMap::GetInstance()
{
	return Instance;
}

void AMiniMap::AddMiniMapMarker_Implementation(AActor* Actor, FVector Location, EMarkerType Marker)
{
	
}


// Called every frame
void AMiniMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

