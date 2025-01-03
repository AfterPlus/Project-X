
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnumLibrary.generated.h"

/** Enum for DataTable Names */
UENUM(BlueprintType, meta=(ScriptName="EnumDataTables"))
enum EMarkerType
{
	EMarkerType_None			UMETA(DisplayName = "None"),
	EMarkerType_Player			UMETA(DisplaName = "Player"),
	EMarkerType_Objective		UMETA(DisplaName = "Objective")
};

UENUM(BlueprintType, meta=(ScriptName="EnumDataTables"))
enum EWeaponType
{
	EWeaponType_None			UMETA(DisplayName = "None"),
	EWeaponType_Pistol			UMETA(DisplaName = "Pistol"),
	EWeaponType_SMG				UMETA(DisplaName = "SMG"),
	EWeaponType_Rifle			UMETA(DisplaName = "Rifle"),
	EWeaponType_ShootGun		UMETA(DisplaName = "ShootGun"),
	EWeaponType_Sniper			UMETA(DisplaName = "Sniper")
};

UENUM(BlueprintType, meta=(ScriptName="EnumDataTables"))
enum EGrenadeType
{
	EGrenadeType_None			UMETA(DisplayName = "None"),
	EGrenadeType_Explosive		UMETA(DisplayName = "Explosive"),
	EGrenadeType_StaticPulse	UMETA(DisplayName = "StaticPulse"),
	EGrenadeType_Decoy			UMETA(DisplayName = "Decoy")
};