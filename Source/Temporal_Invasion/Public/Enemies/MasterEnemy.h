// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Utilities/ActorInterface.h"

#include "MasterEnemy.generated.h"

class AEnemyBullet;
class UBoxComponent;

UCLASS()
class TEMPORAL_INVASION_API AMasterEnemy : public ACharacter,
					public IActorInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMasterEnemy();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variable")
	AMasterGrenade* Grenade;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variable")
	TArray<AEnemyBullet*> Bullets;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variable")
	bool bIsInPlayersAttackRange = false ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variable", meta = (ClampMin = "0.0", ClampMax = "100.0", UIMin = "0.0", UIMax = "100.0"))
	float Health ;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
