// Fill out your copyright notice in the Description page of Project Settings.


#include "Grenade/EnemyGrenade.h"


// Sets default values
AEnemyGrenade::AEnemyGrenade()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemyGrenade::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyGrenade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AEnemyGrenade::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

