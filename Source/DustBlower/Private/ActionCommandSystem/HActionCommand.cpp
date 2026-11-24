// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionCommandSystem/HActionCommand.h"

static TAutoConsoleVariable<bool> CVarDisplayActionCommandDebugMessages(
	TEXT("h.ActionCommand.DebugMessages"), false, TEXT("Display action command debug messages."), ECVF_Cheat);


void UHActionCommand::Execute(AActor* Instigator)
{
#if WITH_EDITOR
	if (!CVarDisplayActionCommandDebugMessages.GetValueOnGameThread())
	{
		UE_LOG(LogTemp, Display,
		       TEXT("Action command debug messages display disabled via cvar 'CVarDisplayActionCommandDebugMessages'"));
		return;
	}

	if (!GEngine)
	{
		return;
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White,
	                                 FString::Printf(TEXT("Executed action %s"), *ActionCommandTag.ToString()));
#endif
}

void UHActionCommand::Undo()
{
#if WITH_EDITOR
	if (!CVarDisplayActionCommandDebugMessages.GetValueOnGameThread())
	{
		UE_LOG(LogTemp, Display,
		       TEXT("Action command debug messages display disabled via cvar 'CVarDisplayActionCommandDebugMessages'"));
		return;
	}

	if (!GEngine)
	{
		return;
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White,
	                                 FString::Printf(TEXT("Undone action %s"), *ActionCommandTag.ToString()));
#endif
}
