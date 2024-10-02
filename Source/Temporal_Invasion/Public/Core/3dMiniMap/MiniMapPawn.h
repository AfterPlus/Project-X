// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MiniMapPawn.generated.h"

class USpringArmComponent;

UCLASS()
class TEMPORAL_INVASION_API AMiniMapPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMiniMapPawn();

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category=Component)
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category=Component)
	USceneComponent* SceneComponent;

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category=Component)
	USceneCaptureComponent2D* CaptureComponent2D;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category=Camera)
	float ZoomSpeed;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category=Camera)
	float MaxZoom = 2500.0f;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category=Camera)
	float MinZoom = 1000.0f;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category=Camera)
	float MoveSpeed = 15.0f;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category=Camera)
	float CameraRotationSpeed ;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	static AMiniMapPawn* GetInstance();

private:
	static AMiniMapPawn* Instance;
};
