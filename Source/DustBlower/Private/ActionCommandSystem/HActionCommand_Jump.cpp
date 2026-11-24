// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionCommandSystem/HActionCommand_Jump.h"

#include "GameFramework/Character.h"


void UHActionCommand_Jump::Execute(AActor* Instigator)
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
