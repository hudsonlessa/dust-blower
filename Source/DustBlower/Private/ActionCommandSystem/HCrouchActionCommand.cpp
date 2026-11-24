// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionCommandSystem/HCrouchActionCommand.h"

#include "GameFramework/Character.h"


void UHCrouchActionCommand::Execute(AActor* Instigator)
{
	Super::Execute(Instigator);

	if (!IsValid(Instigator))
	{
		return;
	}

	CachedInstigatorCharacter = Cast<ACharacter>(Instigator);
	if (!IsValid(CachedInstigatorCharacter))
	{
		return;
	}

	CachedInstigatorCharacter->Crouch();
}

void UHCrouchActionCommand::Undo()
{
	if (!IsValid(CachedInstigatorCharacter))
	{
		return;
	}

	CachedInstigatorCharacter->UnCrouch();

	Super::Undo();
}
