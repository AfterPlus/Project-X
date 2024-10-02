// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/3dMiniMap/MiniMapPawn.h"
#include "Components/SceneCaptureComponent2D.h"
#include "GameFramework/SpringArmComponent.h"

AMiniMapPawn* AMiniMapPawn::Instance = nullptr ;

// Sets default values
AMiniMapPawn::AMiniMapPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SceneComponent->SetupAttachment(RootComponent);
	
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(SceneComponent);

	CaptureComponent2D = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("CaptureComponent2D"));
	CaptureComponent2D->SetupAttachment(SpringArmComponent);
}

// Called when the game starts or when spawned
void AMiniMapPawn::BeginPlay()
{
	Super::BeginPlay();
	Instance = this ;
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

AMiniMapPawn* AMiniMapPawn::GetInstance()
{
	return Instance ;
}

