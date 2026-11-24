// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionCommandSystem/HActionCommand_Crouch.h"

#include "GameFramework/Character.h"


void UHActionCommand_Crouch::Execute(AActor* Instigator)
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

void UHActionCommand_Crouch::Undo()
{
	if (!IsValid(CachedInstigatorCharacter))
	{
		return;
	}

	CachedInstigatorCharacter->UnCrouch();

	Super::Undo();
}
