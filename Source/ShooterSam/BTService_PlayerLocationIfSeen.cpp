// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_PlayerLocationIfSeen.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterAI.h"

UBTService_PlayerLocationIfSeen::UBTService_PlayerLocationIfSeen()
{
	NodeName = TEXT("Update PlayerLocation If Seen");
}

void UBTService_PlayerLocationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AShooterAI*			  OwnerController = Cast<AShooterAI>(OwnerComp.GetAIOwner());
	AShooterSamCharacter* Player = OwnerController->PlayerCharacter;
	UBlackboardComponent* Blackboard = OwnerController->GetBlackboardComponent();

	if (OwnerController && Player && Blackboard)
	{
		if (OwnerController->LineOfSightTo(Player))
		{
			OwnerController->SetFocus(Player);
			Blackboard->SetValueAsVector(GetSelectedBlackboardKey(), Player->GetActorLocation());
		}
		else
		{
			OwnerController->ClearFocus(EAIFocusPriority::Gameplay);
			Blackboard->ClearValue(GetSelectedBlackboardKey());
		}
	}
}
