// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HActionCommand.h"
#include "HSprintActionCommand.generated.h"

class UCharacterMovementComponent;

UCLASS(Abstract, Blueprintable)
class DUSTBLOWER_API UHSprintActionCommand : public UHActionCommand
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
