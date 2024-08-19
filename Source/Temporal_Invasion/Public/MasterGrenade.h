// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Utilities/ActorInterface.h"
#include "MasterGrenade.generated.h"

UENUM(BlueprintType)
enum class EGrenadeState : uint8
{
	EIR_OnGround UMETA(DisplayName = "OnGround"),
	EIR_InHand UMETA(DisplayName = "InHand"),
	EIR_Switch UMETA(DisplayName = "Switch"),
	EIR_InInventory UMETA(DisplayName = "In Inventory"),
	EIR_MAX UMETA(DisplayName = "DafaultMAX")
};

class UBoxComponent;
class UProjectileMovementComponent;
class USphereComponent;

UCLASS(BlueprintType)
class TEMPORAL_INVASION_API AMasterGrenade : public AActor,
	public IActorInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMasterGrenade();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component")
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
	USphereComponent* CollisionBox;

	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component")
	//UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variable")
	EGrenadeState GrenadeState;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Functions")
	void UpdateGrenadeState(EGrenadeState WeaponState);
};
