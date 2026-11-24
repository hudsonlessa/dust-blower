// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HActionCommand.h"
#include "HJumpActionCommand.generated.h"

UCLASS(Abstract, Blueprintable)
class DUSTBLOWER_API UHJumpActionCommand : public UHActionCommand
{
	GENERATED_BODY()

public:
	virtual void Execute(AActor* Instigator) override;
};
