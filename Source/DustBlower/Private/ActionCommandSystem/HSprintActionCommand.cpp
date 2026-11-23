// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionCommandSystem/HSprintActionCommand.h"

#include "GameFramework/CharacterMovementComponent.h"


void UHSprintActionCommand::Execute(AActor* Instigator)
{
	if (!IsValid(Instigator))
	{
		return;
	}

	CMC = Instigator->GetComponentByClass<UCharacterMovementComponent>();
	if (!IsValid(CMC))
	{
		return;
	}

	DefaultSpeed = CMC->MaxWalkSpeed;
	CMC->MaxWalkSpeed = SprintSpeed;

	if (!GEngine)
	{
		return;
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White,
	                                 FString::Printf(TEXT("Executed action %s"), *ActionCommandTag.ToString()));
}

void UHSprintActionCommand::Undo()
{
	if (!IsValid(CMC))
	{
		return;
	}

	CMC->MaxWalkSpeed = DefaultSpeed;

	if (!GEngine)
	{
		return;
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White,
	                                 FString::Printf(TEXT("Undone action %s"), *ActionCommandTag.ToString()));
}
