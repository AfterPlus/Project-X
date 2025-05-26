// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/GrappleComponent.h"


// Sets default values for this component's properties
UGrappleComponent::UGrappleComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrappleComponent::BeginPlay()
{
	Super::BeginPlay();
	
	AActor* Owner = GetOwner();

	if (!Owner) return;

	MeshComponent = NewObject<UStaticMeshComponent>(Owner, TEXT("StaticMeshComp"));
	MeshComponent->SetupAttachment(Owner->GetRootComponent());
	MeshComponent->RegisterComponent();
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	if (USkeletalMeshComponent* SkeletalMesh = Owner->FindComponentByClass<USkeletalMeshComponent>())
	{
		if (SkeletalMesh->DoesSocketExist("Head"))
		{
			HeadLocation = SkeletalMesh->GetSocketLocation("Head");
			// Now you can use HeadLocation
		}
	}

	
	if (Mesh)
		MeshComponent->SetStaticMesh(Mesh);

	if (Material)
		MeshComponent->SetMaterial(0, Material);
	
	HideMarker();
}

// Called every frame
void UGrappleComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                      FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGrappleComponent::ShowMarker_Implementation()
{

	MeshComponent->SetHiddenInGame(false);

	AActor* Owner = GetOwner();
	if (!Owner) return;

	USkeletalMeshComponent* SkeletalMesh = Owner->FindComponentByClass<USkeletalMeshComponent>();
	if (!SkeletalMesh) return;

	if (!SkeletalMesh->DoesSocketExist("Head")) return;

	HeadLocation = SkeletalMesh->GetSocketLocation("Head");
	MeshComponent->SetWorldLocation(HeadLocation);
}


void UGrappleComponent::HideMarker_Implementation()
{
	MeshComponent->SetHiddenInGame(true);
}

