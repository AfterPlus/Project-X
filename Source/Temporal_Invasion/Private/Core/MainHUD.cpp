// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/MainHUD.h"
#include "Utilities/BPFunctionLibrary.h"

AMainHUD* AMainHUD::Instance = nullptr;

void AMainHUD::BeginPlay()
{
	Super::BeginPlay();
	Instance = this;
}

void AMainHUD::ActorOnInitialize_Implementation(AActor* Interact_Actor)
{
	IActorInterface::ActorOnInitialize_Implementation(Interact_Actor);
	
}

void AMainHUD::SetupHUD()
{
	Instance = this;
}

AMainHUD* AMainHUD::GetInstance()
{
	return Instance;
}

