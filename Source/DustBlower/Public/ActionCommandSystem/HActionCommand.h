// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "HActionCommand.generated.h"

UCLASS(Abstract)
class DUSTBLOWER_API UHActionCommand : public UObject
{
	GENERATED_BODY()

public:
	FORCEINLINE FGameplayTag GetActionCommandTag()
	{
		return ActionCommandTag;
	}

	FORCEINLINE void SetActionCommandTag(FGameplayTag InActionCommandTag)
	{
		ActionCommandTag = InActionCommandTag;
	}

	FORCEINLINE FGameplayTagContainer GetUndoActionCommandsWithTags()
	{
		return UndoActionCommandsWithTags;
	}

	FORCEINLINE bool GetIsPersistent()
	{
		return bIsPersistent;
	}

	virtual void Execute(AActor* Instigator) PURE_VIRTUAL(UHActionCommand::Execute);

	virtual void Undo() PURE_VIRTUAL(UHActionCommand::Undo);

protected:
	UPROPERTY(EditDefaultsOnly)
	FGameplayTag ActionCommandTag;

private:
	UPROPERTY(EditDefaultsOnly)
	bool bIsPersistent = false;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTagContainer UndoActionCommandsWithTags;
};
