// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Utilities/EnumLibrary.h"
#include "GameFramework/Actor.h"
#include "Utilities/ActorInterface.h"
#include "MasterWeapon.generated.h"

USTRUCT(BlueprintType)
struct FWeapon 
{
	GENERATED_BODY()

	UPROPERTY( BlueprintReadWrite, meta = (DisplayName = "WeaponName"))
	FString WeaponName;

	// Ammo Details
	UPROPERTY( BlueprintReadWrite, meta = (DisplayName = "MaxAmmo"))
	int MaxAmmo;

	UPROPERTY( BlueprintReadWrite, meta = (DisplayName = "CurrentAmmo"))
	int CurrentAmmo;

	UPROPERTY( BlueprintReadWrite, meta = (DisplayName = "FireRate"))
	float FireRate;

	// HUD
	//UPROPERTY( BlueprintReadWrite, meta = (DisplayName = "Weapon_Icon"))
	//UTexture* Icon;

	// Skeletal mesh
	UPROPERTY( BlueprintReadWrite, meta = (DisplayName = "SkeletalMesh"))
	USkeletalMeshComponent* SkeletalMesh;

	// Animations 
	UPROPERTY( BlueprintReadWrite, meta = (DisplayName = "EquipWeapon"))
	UAnimMontage* EquipWeapon;

	UPROPERTY( BlueprintReadWrite, meta = (DisplayName = "WeaponReload"))
	UAnimMontage* WeaponReload;
	
};

UENUM(BlueprintType)
enum class EWeaponState : uint8
{
	EIR_OnGround UMETA(DisplayName = "OnGround"),
	EIR_InHand UMETA(DisplayName = "InHand"),
	EIR_Switch UMETA(DisplayName = "Switch"),
	EIR_InInventory UMETA(DisplayName = "In Inventory"),
	EIR_MAX UMETA(DisplayName = "DafaultMAX")
};

UENUM(BlueprintType)
enum class EFireMode : uint8
{
	EIR_None UMETA(DisplayName = "None"),
	EIR_Single UMETA(DisplayName = "Single"),
	EIR_Burst UMETA(DisplayName = "Burst"),
	EIR_Auto UMETA(DisplayName = "Auto")
};


class USkeletalMeshComponent;
class USphereComponent;
class AMyCharacter;
//class USceneComponent;

UCLASS()
class TEMPORAL_INVASION_API AMasterWeapon : public AActor,
		public IActorInterface
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	AMasterWeapon();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite,EditAnyWhere,Category="Component")
	USkeletalMeshComponent* GunMesh;

	UPROPERTY(BlueprintReadWrite,EditAnyWhere,Category="Component")
	USkeletalMesh* GunSkeletalMesh;

	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Component")
	USphereComponent* SphereComponent;

	//UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Component")
	//USceneComponent* RootComponent;

	//UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Component")
	//USceneComponent* SceneComponent;

	UPROPERTY(BlueprintReadWrite, Category = "Variables")
	bool bCanPickUpWeapon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	TEnumAsByte<EWeaponType> WeaponTypeEnum;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	AMyCharacter* AsPlayerCharacter;

	/** The current number of bullets in the gun */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	float CurrentAmmo;

	/**  The number of bullets currently loaded in the weapon's clip */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	float AmmoInClip;

	/** The maximum number of bullets that the weapon's clip can hold */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	float MaxAmmoInClip;

	/** The name of the weapon */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	FText WeaponName;

	/** Icon for the weapon */
	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Variables")
	UTexture* Icon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	UUserWidget* InteractiveWidget;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	EFireMode FireMode ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	float Damage ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	float Range ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	float Spread ;

	UPROPERTY(BlueprintReadWrite, Category = "Variables")
	float RecoilAlpha ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	FVector ADS_Offset;

	/** Enum for fot the weapon to indicate what state is the weapon at */
	UPROPERTY(BlueprintReadWrite, Category = "Variables")
	EWeaponState E_WeaponState;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	bool bCanFire;

	UPROPERTY(BlueprintReadWrite, Category = "Variables")
	bool bIsReloading = false ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Animations")
	UAnimMontage* ReloadAnimation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Animations")
	UAnimMontage* FireAnimation;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void StartWeaponFire_Implementation() override ;
	virtual void StopWeaponFire_Implementation() override;
	virtual  void WeaponReload_Implementation() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Functions")
	bool BeginLineTraceToDeductWeapon();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Functions")
	void UpdateWeaponState(EWeaponState WeaponState);
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Functions")
	void Reload(UAnimMontage* ReloadMontage);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Functions")
	void UpdateCrosshair(EWeaponType WeaponType);
};
