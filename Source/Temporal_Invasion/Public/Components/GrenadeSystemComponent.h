#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Utilities/ActorInterface.h"
#include "Utilities/EnumLibrary.h"
#include "GrenadeSystemComponent.generated.h"

class AMyCharacter;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class TEMPORAL_INVASION_API UGrenadeSystemComponent : public UActorComponent,
	public IActorInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGrenadeSystemComponent();
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	AMyCharacter* AsMyCharacter;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void StartWeaponFire_Implementation() override ;
	virtual void StopWeaponFire_Implementation() override;
	virtual  void WeaponReload_Implementation() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
		FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PickUp(EGrenadeType GrenadeType);
};
