// Fill out your copyright notice in the Description page of Project Settings.


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

void UGameInstanceBase::SaveWeaponInfo_Implementation(int CurrentAmmo, int MaxAmmo)
{
	
}

void UGameInstanceBase::SavePlayer_Implementation(FPlayerSaveData SaveData)
{
	
}

void UGameInstanceBase::SaveCharacterStats_Implementation(FCharactersStats Stats)
{
	
}

void UGameInstanceBase::UpgradeSkillType_Implementation(ESkillType SkillType)
{
	
}

void UGameInstanceBase::LoadSkills_Implementation()
{
	
}
