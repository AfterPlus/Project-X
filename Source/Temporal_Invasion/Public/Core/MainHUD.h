// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Utilities/ActorInterface.h"
#include "GameFramework/HUD.h"
#include "MainHUD.generated.h"

/**
 * 
 */
UCLASS()
class TEMPORAL_INVASION_API AMainHUD : public AHUD,
	public IActorInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Widget")
	UUserWidget* Wbp_WeaponWheel;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Widgets")
	UUserWidget* Wbp_HUD;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Widgets")
	UUserWidget* Wbp_RadialMenu;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Widgets")
	UUserWidget* Wbp_Crosshair;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Widgets")
	UUserWidget* Wbp_SkillUpgrades;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Widgets")
	TArray<UUserWidget*> AllWidgets;
	
	virtual void ActorOnInitialize_Implementation(AActor* Interact_Actor) override;

protected:
	static AMainHUD* Instance;

public:

	void SetupHUD();
	
	UFUNCTION(BlueprintCallable,BlueprintPure, meta = (DisplayName = "Get Main HUD"))
	static AMainHUD* GetInstance();

	virtual void BeginPlay() override;
};
