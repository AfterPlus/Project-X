#include "MasterGrenade.h"

#include "MasterWeapon.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Core/MyCharacter.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AMasterGrenade::AMasterGrenade()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent); // Attach the Mesh to the root component
	
	// Create the Collision Box and Mesh component
	CollisionBox = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionBox"));
	CollisionBox->SetupAttachment(Mesh);  // Set the CollisionBox as the mesh

	//ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	
	// Set up the overlap event
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AMasterGrenade::OnOverlapBegin);
	
	// Enable collision
	// CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	// CollisionBox->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	// CollisionBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	// CollisionBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
}

// Called when the game starts or when spawned
void AMasterGrenade::BeginPlay()
{
	Super::BeginPlay();
	UpdateGrenadeState(EGrenadeState::EIR_InHand);
}

// Called every frame
void AMasterGrenade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMasterGrenade::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AMyCharacter* Character = Cast<AMyCharacter>(OtherActor);
	if (Character)
	{
		Character->AddGrenadeClass_Implementation(GetClass());
		Destroy();
	}
}

void AMasterGrenade::UpdateGrenadeState_Implementation(EGrenadeState WeaponState)
{
	switch (GrenadeState)
	{
	case EGrenadeState::EIR_InHand:
		CollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		break;

	case EGrenadeState::EIR_OnGround:
		CollisionBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
		CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		break;
	}
}
