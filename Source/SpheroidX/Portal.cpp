// copyright Benedikt Orn Hjaltason
// *****---->PC VERSION <----*****


#include "Portal.h"

// Sets default values
APortal::APortal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	PortalPlane1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Portal Plane1"));
	PortalPlane2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Portal Plane2"));

	RootComponent = SceneRoot;
	PortalPlane1->SetupAttachment(SceneRoot);
	PortalPlane2->SetupAttachment(SceneRoot);
}

// Called when the game starts or when spawned
void APortal::BeginPlay()
{
	Super::BeginPlay();
	SetActorHiddenInGame(true);
}

// Called every frame
void APortal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PortalPlane1->AddWorldRotation(BaseRotateDelta);
	PortalPlane2->AddWorldRotation(CenterRotateDelta);

}

