// Fill out your copyright notice in the Description page of Project Settings.

#include "Gun.h"

#include "Kismet/GameplayStatics.h"
#include "Engine/DamageEvents.h"

// Sets default values
AGun::AGun()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	SetRootComponent(SceneComp);

	SkeletaMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletaMeshComp"));
	SkeletaMeshComp->SetupAttachment(SceneComp);

	MuzzleFlashParticleSystem = CreateDefaultSubobject<UNiagaraComponent>(TEXT("MuzzleFlash"));
	MuzzleFlashParticleSystem->SetupAttachment(SkeletaMeshComp);
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();

	MuzzleFlashParticleSystem->Deactivate();
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGun::PullTrigger()
{
	MuzzleFlashParticleSystem->Activate(true);
	if (OwnerController)
	{
		FVector	 Location;
		FRotator Rotation;
		OwnerController->GetPlayerViewPoint(Location, Rotation);

		FVector EndLocation = Location + Rotation.Vector() * MaxRange;

		FHitResult Result;

		FCollisionQueryParams Params;
		Params.AddIgnoredActor(this);
		Params.AddIgnoredActor(GetOwner());
		if (GetWorld()->LineTraceSingleByChannel(Result, Location, EndLocation, ECollisionChannel::ECC_GameTraceChannel2, Params))
		{
			if (ImpactParticleSystem)
			{
				UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ImpactParticleSystem, Result.ImpactPoint, Result.ImpactPoint.Rotation());
			}
			if (auto HitActor = Result.GetActor())
			{
				// two ways to take damage

				// UGameplayStatics::ApplyDamage(HitActor, BulletDamage, OwnerController, this, UDamageType::StaticClass());
				HitActor->TakeDamage(BulletDamage, FDamageEvent(UDamageType::StaticClass()), OwnerController, this);
			}
		}
	}
}
