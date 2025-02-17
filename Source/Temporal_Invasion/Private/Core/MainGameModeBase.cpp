// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/MainGameModeBase.h"
#include "Utilities/EventsHolder.h"

AMainGameModeBase* AMainGameModeBase::Instance = nullptr ;

void AMainGameModeBase::Init()
{
	Instance = this;
	EventsHolder = NewObject<UEventsHolder>(this);
}

void AMainGameModeBase::UpgradeSkillType_Implementation(ESkillType SkillType)
{
	
}

void AMainGameModeBase::LoadSkills_Implementation()
{
	
}

void AMainGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	Instance = this ;

	
	//EventsHolder->ini
}

AMainGameModeBase* AMainGameModeBase::GetInstance()
{
	
	return Instance ;
	
}




