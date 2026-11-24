// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HActionCommand.h"
#include "HActionCommand_Crouch.generated.h"

UCLASS(Abstract, Blueprintable)
class DUSTBLOWER_API UHActionCommand_Crouch : public UHActionCommand
{
	GENERATED_BODY()

public:
	virtual void Execute(AActor* Instigator) override;

	virtual void Undo() override;

private:
	UPROPERTY()
	TObjectPtr<ACharacter> CachedInstigatorCharacter;
};
