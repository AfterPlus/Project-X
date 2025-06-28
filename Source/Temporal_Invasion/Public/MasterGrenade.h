// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemies/MasterEnemy.h"
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

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variable")
	USoundBase* BounceSound;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variable")
	bool bHasBeenThrown ; 

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variable", meta=(ExposeOnSpawn=true))
	bool Player ;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variable", meta=(ExposeOnSpawn=true))
	AMasterEnemy* Enemy ;

	UPROPERTY(VisibleAnywhere)
	UAudioComponent* AudioComponent;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Functions")
	void Throw();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Functions")
	void EnemyThrow(FVector Impulse);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Functions")
	void ResetProperties();
};
