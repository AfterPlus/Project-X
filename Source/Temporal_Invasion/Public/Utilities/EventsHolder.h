// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Utilities/EnumLibrary.h"
#include "UObject/Object.h"
#include "EventsHolder.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FUpdateMiniMapMarker,AActor*,Actor,FVector,Location,UStaticMeshComponent*,MeshComponent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FApplyOption);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAmmoCountAnim);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayHUDFireAnimation,EWeaponType,WeaponType);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUpdateCrosshair,EWeaponType,WeaponType);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUpdatePlayerHealth,float,Amount,AActor*,Actor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUpdatePlayerArmor,float,Amount,AActor*,Actor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FWeaponAmmoPick,float,Amount,EWeaponType,WeaponType);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDash,bool,bUpdateTextOnly);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGrapple,bool,bUpdateTextOnly);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAreaCleared);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FPickUpNotification,UTexture2D*,Image,FText,Name,FText,Amount);


UCLASS()
class TEMPORAL_INVASION_API UEventsHolder : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable,BlueprintCallable)
	FUpdateMiniMapMarker UpdateMiniMapMarkerReq;

	UPROPERTY(BlueprintAssignable,BlueprintCallable)
	FApplyOption ApplyOptionReq;

	UPROPERTY(BlueprintAssignable,BlueprintCallable)
	FDash Dash;

	UPROPERTY(BlueprintAssignable,BlueprintCallable)
	FGrapple Grapple;

	UPROPERTY(BlueprintAssignable,BlueprintCallable)
	FPlayHUDFireAnimation PlayHUDFireAnimationReq;

	UPROPERTY(BlueprintAssignable,BlueprintCallable)
	FUpdateCrosshair UpdateCrosshairReq;

	UPROPERTY(BlueprintAssignable,BlueprintCallable)
	FAmmoCountAnim PlayAmmoCountAnim ;

	UPROPERTY(BlueprintAssignable,BlueprintCallable)
	FUpdatePlayerHealth UpdatePlayerHealth;

	UPROPERTY(BlueprintAssignable,BlueprintCallable)
	FUpdatePlayerArmor UpdatePlayerArmor ;

	UPROPERTY(BlueprintAssignable,BlueprintCallable)
	FWeaponAmmoPick WeaponAmmoPicked ;

	UPROPERTY(BlueprintAssignable,BlueprintCallable)
	FPickUpNotification PickUpNotification ;

	UPROPERTY(BlueprintAssignable,BlueprintCallable)
	FAreaCleared AreaCleared ;
};
