// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionCommandSystem/HSprintActionCommand.h"

#include "GameFramework/CharacterMovementComponent.h"


void UHSprintActionCommand::Execute(AActor* Instigator)
{
	Super::Execute(Instigator);

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
}

void UHSprintActionCommand::Undo()
{
	if (!IsValid(CMC))
	{
		return;
	}

	CMC->MaxWalkSpeed = DefaultSpeed;

	Super::Undo();
}
