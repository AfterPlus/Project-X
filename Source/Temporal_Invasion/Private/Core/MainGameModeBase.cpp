// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/MainGameModeBase.h"

AMainGameModeBase* AMainGameModeBase::Instance = nullptr ;

void AMainGameModeBase::Init()
{
	Instance = this;
}

void AMainGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	Instance = this ;
}

AMainGameModeBase* AMainGameModeBase::GetInstance()
{
	return Instance ; 
}




