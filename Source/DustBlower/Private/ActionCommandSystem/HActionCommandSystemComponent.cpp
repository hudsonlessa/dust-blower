// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionCommandSystem/HActionCommandSystemComponent.h"

#include "GameplayTagContainer.h"
#include "ActionCommandSystem/HActionCommand.h"


// Sets default values for this component's properties
UHActionCommandSystemComponent::UHActionCommandSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UHActionCommandSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	for (const TSubclassOf<UHActionCommand> DefaultActionCommandClass : DefaultActionCommandClasses)
	{
		UHActionCommand* NewActionCommand = NewObject<UHActionCommand>(this, DefaultActionCommandClass);
		EnabledActionCommands.AddUnique(NewActionCommand);
	}
}

// Called every frame
void UHActionCommandSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                   FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHActionCommandSystemComponent::ExecuteActionCommand(FGameplayTag ActionCommandTag)
{
	if (PersistentActionCommandsTags.HasTagExact(ActionCommandTag))
	{
		UndoActionCommand(ActionCommandTag);
		return;
	}

	UHActionCommand* ActionCommand = FindActionCommand(ActionCommandTag, EnabledActionCommands);
	if (!IsValid(ActionCommand))
	{
		return;
	}

	ActionCommand->Execute(GetOwner());

	if (!ActionCommand->GetIsPersistent())
	{
		return;
	}

	PersistentActionCommandsTags.AddTag(ActionCommandTag);
}

void UHActionCommandSystemComponent::UndoActionCommand(FGameplayTag ActionCommandTag)
{
	if (!PersistentActionCommandsTags.HasTagExact(ActionCommandTag))
	{
		return;
	}

	UHActionCommand* ActionCommand = FindActionCommand(ActionCommandTag, EnabledActionCommands);
	if (!IsValid(ActionCommand))
	{
		return;
	}

	ActionCommand->Undo();
	PersistentActionCommandsTags.RemoveTag(ActionCommandTag);
}

UHActionCommand* UHActionCommandSystemComponent::FindActionCommand(FGameplayTag ActionCommandTag,
                                                                   TArray<UHActionCommand*> ActionCommands)
{
	for (UHActionCommand* ActionCommand : ActionCommands)
	{
		if (ActionCommand->GetActionCommandTag() != ActionCommandTag)
		{
			continue;
		}

		return ActionCommand;
	}

	return nullptr;
}

void UHActionCommandSystemComponent::UndoActionCommands(FGameplayTagContainer ActionCommandTags)
{
	for (const FGameplayTag ActionCommandTag : ActionCommandTags)
	{
		UndoActionCommand(ActionCommandTag);
	}
}
