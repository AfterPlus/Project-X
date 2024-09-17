// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MiniMap.generated.h"

class USpringArmComponent;

UCLASS()
class TEMPORAL_INVASION_API AMiniMap : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMiniMap();
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="MiniMap")
	UStaticMeshComponent* MiniMapMesh;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="MiniMap")
	USceneCaptureComponent2D* SceneCaptureComponent;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="MiniMap")
	USpringArmComponent* SpringArmComponent;


	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
