// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "HSprintComponent.generated.h"


class UHStateManagerComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent, DisplayName="Sprint Component"))
class DUSTBLOWER_API UHSprintComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHSprintComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	bool CanSprint();

	void ToggleSprint();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	float DefaultSpeed = 0.0f;

	UPROPERTY(EditDefaultsOnly)
	float SprintSpeed = 0.0f;

	void StartSprint();

	void StopSprint();

	UCharacterMovementComponent* GetOwnerCharacterMovementComponent();

	UHStateManagerComponent* GetOwnerStateManagerComponent();
};
