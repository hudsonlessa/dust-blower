// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "HStateManagerComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent, DisplayName="State Manager Component"))
class DUSTBLOWER_API UHStateManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHStateManagerComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	void ActivateState(FGameplayTag State);

	void DeactivateState(FGameplayTag State);

	bool HasActiveState(FGameplayTag State);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	FGameplayTagContainer ActiveStates;
};
