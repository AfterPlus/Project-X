// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/MasterEnemy.h"

#include "Components/BoxComponent.h"


// Sets default values
AMasterEnemy::AMasterEnemy()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Health = 100.f ;
	
}

// Called when the game starts or when spawned
void AMasterEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMasterEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMasterEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


