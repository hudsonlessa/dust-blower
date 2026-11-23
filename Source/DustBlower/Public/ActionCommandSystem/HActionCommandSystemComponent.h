// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "HActionCommandSystemComponent.generated.h"

struct FGameplayTagContainer;
class UHActionCommand;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DUSTBLOWER_API UHActionCommandSystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHActionCommandSystemComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	void ExecuteActionCommand(FGameplayTag ActionCommandTag);

	void UndoActionCommand(FGameplayTag ActionCommandTag);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<UHActionCommand>> DefaultActionCommandClasses;

	UPROPERTY()
	TArray<UHActionCommand*> EnabledActionCommands;

	UPROPERTY()
	FGameplayTagContainer PersistentActionCommandsTags;

	UHActionCommand* FindActionCommand(FGameplayTag ActionCommandTag, TArray<UHActionCommand*> ActionCommands);
	
	void UndoActionCommands(FGameplayTagContainer ActionCommandTags);
};
