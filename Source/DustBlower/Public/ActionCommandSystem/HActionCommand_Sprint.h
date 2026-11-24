// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HActionCommand.h"
#include "HActionCommand_Sprint.generated.h"

class UCharacterMovementComponent;

UCLASS(Abstract, Blueprintable)
class DUSTBLOWER_API UHActionCommand_Sprint : public UHActionCommand
{
	GENERATED_BODY()

public:
	virtual void Execute(AActor* Instigator) override;

	virtual void Undo() override;

private:
	float DefaultSpeed = 0.0f;

	UPROPERTY(EditDefaultsOnly)
	float SprintSpeed = 0.0f;

	UPROPERTY()
	TObjectPtr<UCharacterMovementComponent> CMC;
};
