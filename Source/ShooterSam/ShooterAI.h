// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterSamCharacter.h"

#include "ShooterAI.generated.h"

/**
 *
 */
UCLASS()
class SHOOTERSAM_API AShooterAI : public AAIController
{
	GENERATED_BODY()
public:
	void StartBehaviorTree(AShooterSamCharacter* Player);

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UBehaviorTree* EnemyAIBehaviorTree;

	AShooterSamCharacter* PlayerCharacter;
	AShooterSamCharacter* MyCharacter;
};
