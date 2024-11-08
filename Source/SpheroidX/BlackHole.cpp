﻿// copyright Benedikt Orn Hjaltason
// *****---->PC VERSION <----*****


#include "BlackHole.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Public/DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "Avatar.h"

// Sets default values
ABlackHole::ABlackHole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	Plane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Image Plane"));
	Torus = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Torus"));
	MeasureActor = CreateDefaultSubobject<UChildActorComponent>(TEXT("MeasureActor"));

	Collider->SetSphereRadius(50);
	RootComponent = Collider;

	Plane->SetupAttachment(Collider);
	Torus->SetupAttachment(Collider);
	MeasureActor->SetupAttachment(Collider);
}

// Called when the game starts or when spawned
void ABlackHole::BeginPlay()
{
	Super::BeginPlay();
	Spheroid = Cast<AAvatar>(UGameplayStatics::GetPlayerPawn(GetWorld(),0));
	CurrentWorld = GetWorld();
	CurrentLocationThis = GetActorLocation();


}

// Called every frame
void ABlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentDistanceToSpheroid = GetDistanceTo(Spheroid);
	if (CurrentDistanceToSpheroid < radius)
	{
		AttractScale = (7500 / CurrentDistanceToSpheroid);

		Spheroid->Collision->AddForce((CurrentLocationThis - Spheroid->GetActorLocation()) *  AttractScale);
	}
}

