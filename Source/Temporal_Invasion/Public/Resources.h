// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Utilities/ActorInterface.h"
#include "GameFramework/Actor.h"
#include "Resources.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class TEMPORAL_INVASION_API AResources : public AActor,
	public IActorInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AResources();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component")
	UStaticMeshComponent* Mesh ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component")
	USphereComponent* PickUpRadius ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component")
	UProjectileMovementComponent* ProjectileMovementComponent ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variable")
	UTexture2D* Icon ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variable")
	FText ResourceName ;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
