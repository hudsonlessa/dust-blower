// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionCommandSystem/HJumpActionCommand.h"

#include "GameFramework/Character.h"


void UHJumpActionCommand::Execute(AActor* Instigator)
{
	Super::Execute(Instigator);

	if (!IsValid(Instigator))
	{
		return;
	}

	ACharacter* InstigatorCharacter = Cast<ACharacter>(Instigator);
	if (!IsValid(InstigatorCharacter))
	{
		return;
	}

	InstigatorCharacter->Jump();
}
