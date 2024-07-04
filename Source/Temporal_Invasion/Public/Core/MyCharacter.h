// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Utilities/ActorInterface.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

class AMainHUD;
class AMainGameModeBase;
class AMainPlayerController;
class UGrenadeSystemComponent;
class UWeaponSystemComponent;
class AMasterWeapon;
class UWidgetComponent;
UCLASS()
class TEMPORAL_INVASION_API AMyCharacter : public ACharacter,
	public IActorInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();
	// cast to core main
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Components")
	AMainPlayerController* AsMainPlayerController ;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Components")
	AMainGameModeBase* AsMainGameMode ;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Components")
	AMainHUD* AsMainHUD ;
	
	/** Component for the guns to be placed */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Components")
	USkeletalMeshComponent* GunMesh ;

	/** Component for the guns to be placed */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Components")
	USkeletalMeshComponent* GunHolder ;

	/** Interact widget display when overlap weapon class */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Variables")
	UWidgetComponent* InteractWidget ;

	/** Interact widget display when overlap weapon class */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Variables")
	UWidgetComponent* WBP_RadialMenu ;

	/** Time handler  */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Procedural Animation")
	FTimerHandle UncrouchTimer ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Procedural Animation")
	FTimerHandle CoyoteTimer ;

	/** Crouch Alpha from the timeline */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Procedural Animation")
	float CrouchAlpha ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Procedural Animation")
	float DipStrength ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Procedural Animation")
	float DipAlpha ;

	/** Base walk speed */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Procedural Animation")
	float BaseWalkSpeed ;

	/** capsule size of the character when stand */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Procedural Animation")
	float StandHeight ;
	
	/** capsule size of the character when crouch */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Procedural Animation")
	float CrouchHeight ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Procedural Animation")
	float CoyoteTime ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Procedural Animation")
	float WalkAnimAlpha ;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Procedural Animation")
	FVector LocationLagPos ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Procedural Animation")
	FRotator WalkAnimRot ;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Procedural Animation")
	FVector WalkAnimPos ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Procedural Animation")
	FVector PitchOffsetPos ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Procedural Animation")
	FVector CameraRotOffset ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Procedural Animation")
	FRotator CameraRotCurrent ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Procedural Animation")
	FRotator CameraRotRate ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Procedural Animation")
	FRotator InAirTilt ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Procedural Animation")
	FVector InAirOffset ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Procedural Animation")
	FVector PrevHandLock  ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Procedural Animation")
	FVector CamOffset ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Procedural Animation")
	float CameraStrength  ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Procedural Animation")
	FVector CamOffsetCurrent ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Procedural Animation")
	float CamAnimAlpha ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Procedural Animation")
	FVector ADS_Offset ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Procedural Animation")
	float ADSSpeed ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Procedural Animation")
	float ADSAlpha ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Procedural Animation")
	float FOVBase ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Procedural Animation")
	float FOVADS ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Procedural Animation")
	bool ADS_Held ;
	
	/** List of weapons the player is carrying  */
	UPROPERTY(BlueprintReadWrite, Category="Weapon")
	TArray<AMasterWeapon*> AllWeapons ;

	UPROPERTY(BlueprintReadWrite, Category="Weapon")
	TArray<USceneComponent*> WeaponSlots ;
	
	/** The number od slots the player has to carry weapons */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon")
	int InventorySlots = 0;

	/** Current weapon slot the player is using */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon")
	int WeaponIndex ;

	/** Weapon to spawn when game starts */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon")
	AMasterWeapon* OnStartWeapon ;

	/** Weapon that the player is currently using */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon")
	AMasterWeapon* InHandWeapon ;
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, Category="Components")
	UWeaponSystemComponent* WeaponSystemComponent;

	UPROPERTY(BlueprintReadWrite, Category="Components")
	UGrenadeSystemComponent* GrenadeSystemComponent;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Functions")
	void CastToCoreMain();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Functions")
	void EquipWeapon(int Index);

	/** Spawn a weapon and attach to the players hand on begin play */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Functions")
	void EquipWeaponOnStart();

	/** Switch weapon on input */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Functions")
	void SwitchWeapon(int Index);
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Procedural Animation")
	void StandUp();

	/** Check if the player can stand under any surface */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Procedural Animation")
	bool CheckCanStand();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Procedural Animation")
	void GetVelocityVar(); 
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Procedural Animation")
	void CoyoteTimePasses();

	/** Landing DIP */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Procedural Animation")
	void LandingDip() ;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Procedural Animation")
	void Dip(float Speed, float Strength) ;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Procedural Animation")
	bool GetLookInputVars (FRotator CamRotPrev) ;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Procedural Animation")
	void ExitADS(bool Fast) ;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Procedural Animation")
	void EnterADS() ;
	
	/** TEST */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Functions")
	void SpawnWeapon(TSubclassOf<AMasterWeapon> WeaponClass);

};
