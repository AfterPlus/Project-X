#include "MasterGrenade.h"

#include "MasterWeapon.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Core/MyCharacter.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMasterGrenade::AMasterGrenade()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent); // Attach the Mesh to the root component
	Mesh ->SetCollisionProfileName(TEXT("BlockAllDynamic"));
	
	CollisionBox = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionBox"));
	CollisionBox->SetupAttachment(Mesh);  // Set the CollisionBox as the mesh
	
	MeshCollision = CreateDefaultSubobject<USphereComponent>(TEXT("MeshCollision"));
	MeshCollision->SetupAttachment(Mesh);  // Set the MeshCollision as the mesh
	
	// Set up the overlap event
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AMasterGrenade::OnOverlapBegin);
	MeshCollision->OnComponentBeginOverlap.AddDynamic(this,&AMasterGrenade::OnOverlapBegin_MeshCollision);
	
	// Enable collision
	// CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	// CollisionBox->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	// CollisionBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	// CollisionBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Mesh->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	Mesh->SetCollisionResponseToChannels(ECollisionResponse::ECR_Overlap);
	Mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
}

// Called when the game starts or when spawned
void AMasterGrenade::BeginPlay()
{
	Super::BeginPlay();
	UpdateGrenadeState(GrenadeState);
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

void AMasterGrenade::OnOverlapBegin_MeshCollision(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
		// If it's not a character or the component doesn't belong to the character, play the bounce sound
		if (BounceSound)
		{
			UGameplayStatics::PlaySoundAtLocation(this, BounceSound, SweepResult.Location);
		}
	
}

void AMasterGrenade::Throw_Implementation()
{
	
}

void AMasterGrenade::UpdateGrenadeState_Implementation(EGrenadeState WeaponState)
{
	switch (WeaponState)
	{
	case EGrenadeState::EIR_InHand:
		// Collision Box
		CollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		// Mesh Collision
		//MeshCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		break;

	case EGrenadeState::EIR_OnGround:
		// Collision Box
		CollisionBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
		CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		// Mesh Collision
		//MeshCollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
		//MeshCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		break;

	default:
		break;
	}
}

