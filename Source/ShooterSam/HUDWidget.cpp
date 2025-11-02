// Fill out your copyright notice in the Description page of Project Settings.

#include "HUDWidget.h"

#include "Math/UnrealMathUtility.h"

void UHUDWidget::SetHealthBarPercent(float NewPercent)
{
	NewPercent = FMath::Clamp(NewPercent, 0.0f, 1.0f);

	if (HealthBar)
	{
		HealthBar->SetPercent(NewPercent);
	}
}
