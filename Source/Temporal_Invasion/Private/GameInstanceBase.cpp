﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstanceBase.h"

UGameInstanceBase* UGameInstanceBase::Instance = nullptr ;

void UGameInstanceBase::Init()
{
	Super::Init();
	Instance = this;
}

UGameInstanceBase* UGameInstanceBase::GetInstance()
{
	return Instance;
}

void UGameInstanceBase::UpgradeSkillType_Implementation(ESkillType SkillType)
{
	
}

void UGameInstanceBase::LoadSkills_Implementation()
{
	
}
