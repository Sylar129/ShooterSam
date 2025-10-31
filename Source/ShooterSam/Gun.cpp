// Fill out your copyright notice in the Description page of Project Settings.

#include "Gun.h"

// Sets default values
AGun::AGun()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	SetRootComponent(SceneComp);

	SkeletaMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletaMeshComp"));
	SkeletaMeshComp->SetupAttachment(SceneComp);
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGun::PullTrigger()
{
	if (OwnerController)
	{
		FVector	 Location;
		FRotator Rotation;
		OwnerController->GetPlayerViewPoint(Location, Rotation);

		DrawDebugCamera(GetWorld(), Location, Rotation, 90, 2, FColor::Red, true);
	}
}
