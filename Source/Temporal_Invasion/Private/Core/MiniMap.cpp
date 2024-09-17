// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/MiniMap.h"

#include "Components/SceneCaptureComponent2D.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
AMiniMap::AMiniMap()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MiniMapMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MiniMapMesh"));
	MiniMapMesh->SetupAttachment(RootComponent);

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);

	SceneCaptureComponent = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("SceneComponent"));
	SceneCaptureComponent->SetupAttachment(SpringArmComponent);
	
}

// Called when the game starts or when spawned
void AMiniMap::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMiniMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}





