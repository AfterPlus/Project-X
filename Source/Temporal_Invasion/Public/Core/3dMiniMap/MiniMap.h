// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Utilities/EnumLibrary.h"
#include "GameFramework/Actor.h"
#include "MiniMap.generated.h"

class AMainGameModeBase;

UCLASS()
class TEMPORAL_INVASION_API AMiniMap : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMiniMap();

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category=Component)
	UStaticMeshComponent* MiniMapMesh;

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category=Component)
	AMainGameModeBase* MainGameModeBase;

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category=Variable)
	float ScaleFactor;

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category=Variable)
	FVector OriginalScale;

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category=Variable)
	FVector SmallerScale;

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category=Variable)
	TArray<AActor*> Actors;
	
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category=Variable)
	TArray<UStaticMeshComponent*> MiniMapMarkers ;  

	UFUNCTION(BlueprintCallable)
	void Init();

public:
	UFUNCTION(BlueprintCallable)
	static AMiniMap* GetInstance();

	UFUNCTION(BlueprintNativeEvent)
	void AddMiniMapMarker(AActor* Actor, FVector Location,UStaticMeshComponent* MeshComponent);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void HideAllMarkers();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ShowAllMarkers();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	static AMiniMap* Instance;
	
};
