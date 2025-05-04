#include "MasterGrenade.h"

#include "Components/SphereComponent.h"

// Sets default values
AMasterGrenade::AMasterGrenade()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	Player = true ;

}

// Called when the game starts or when spawned
void AMasterGrenade::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMasterGrenade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMasterGrenade::EnemyThrow_Implementation(FVector Impulse)
{
	
}

void AMasterGrenade::ResetProperties_Implementation()
{
	
}


void AMasterGrenade::Throw_Implementation()
{
	
}


