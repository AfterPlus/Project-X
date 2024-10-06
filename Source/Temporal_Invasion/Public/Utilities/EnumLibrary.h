
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