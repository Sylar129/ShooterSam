// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Components/SkeletalMeshComponent.h"

#include "Gun.generated.h"

UCLASS()
class SHOOTERSAM_API AGun : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneComp;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* SkeletaMeshComp;

	UPROPERTY(EditAnywhere)
	float MaxRange = 10000;

	AController* OwnerController;

	void PullTrigger();
};
