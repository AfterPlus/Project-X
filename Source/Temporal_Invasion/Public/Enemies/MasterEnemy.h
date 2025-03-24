// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "MasterEnemy.generated.h"

class UBoxComponent;

UCLASS()
class TEMPORAL_INVASION_API AMasterEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMasterEnemy();


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	UBoxComponent* BoxComp;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
