// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/3dMiniMap/MiniMapPawn.h"


// Sets default values
AMiniMapPawn::AMiniMapPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMiniMapPawn::BeginPlay()
{
	Super::BeginPlay();
	
}
// Called every frame
void AMiniMapPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMiniMapPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

