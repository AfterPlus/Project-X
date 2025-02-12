// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GrappleComponent.generated.h"


UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class TEMPORAL_INVASION_API UGrappleComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGrappleComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Variables")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Variables")
	UMaterial* Material;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Variables")
	UStaticMesh* Mesh;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category="GrappleComponent")
	void ShowMarker();

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category="GrappleComponent")
	void HideMarker();
};
