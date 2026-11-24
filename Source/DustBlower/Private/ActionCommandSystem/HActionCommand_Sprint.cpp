// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionCommandSystem/HActionCommand_Sprint.h"

#include "GameFramework/CharacterMovementComponent.h"


void UHActionCommand_Sprint::Execute(AActor* Instigator)
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

void UHActionCommand_Sprint::Undo()
{
	if (!IsValid(CMC))
	{
		return;
	}

	CMC->MaxWalkSpeed = DefaultSpeed;

	Super::Undo();
}
