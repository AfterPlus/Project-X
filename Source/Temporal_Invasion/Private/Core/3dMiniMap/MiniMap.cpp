
#include "Core/3dMiniMap/MiniMap.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Core/MainGameModeBase.h"
#include "GameFramework/SpringArmComponent.h"

AMiniMap* AMiniMap::Instance = nullptr ; 

// Sets default values
AMiniMap::AMiniMap()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MiniMapMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MiniMapMesh"));
	MiniMapMesh->SetupAttachment(RootComponent);

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);

	SceneCaptureComponent = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("SceneComponent"));
	SceneCaptureComponent->SetupAttachment(SpringArmComponent);
	
	AsMainGameModeBase = AMainGameModeBase::GetInstance();
}

// Called when the game starts or when spawned
void AMiniMap::BeginPlay()
{
	Super::BeginPlay();
	Instance = this;
	
}

// Called every frame
void AMiniMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

AMiniMap* AMiniMap::GetInstance()
{
	return Instance;
}




