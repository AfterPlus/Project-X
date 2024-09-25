// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MiniMap.generated.h"

UCLASS()
class TEMPORAL_INVASION_API AMiniMap : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMiniMap();

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category=Component)
	UStaticMeshComponent* MiniMapMesh;

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category=Variable)
	float ScaleFactor;

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category=Variable)
	FVector OriginalScale;

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category=Variable)
	FVector SmallerScale;


public:
	UFUNCTION(BlueprintCallable)
	static AMiniMap* GetInstance();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	static AMiniMap* Instance;

	
};
