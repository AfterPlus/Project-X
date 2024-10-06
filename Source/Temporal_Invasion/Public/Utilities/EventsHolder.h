// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Utilities/EnumLibrary.h"
#include "UObject/Object.h"
#include "EventsHolder.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FUpdateMiniMapMarker,AActor*,Actor,FVector,Location,EMarkerType,Marker);
UCLASS()
class TEMPORAL_INVASION_API UEventsHolder : public UObject
{
	GENERATED_BODY()

	UPROPERTY(BlueprintAssignable,BlueprintCallable)
	FUpdateMiniMapMarker UpdateMiniMapMarkerReq;
};
