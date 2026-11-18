// Fill out your copyright notice in the Description page of Project Settings.


#include "HSprintComponent.h"

#include "HGameplayTags.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "HStateManagerComponent.h"
#include "Player/HPlayerCharacter.h"


// Sets default values for this component's properties
UHSprintComponent::UHSprintComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHSprintComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void UHSprintComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                      FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!CanSprint())
	{
		StopSprint();
	}
}

bool UHSprintComponent::CanSprint()
{
	AHPlayerCharacter* Owner = GetOwner<AHPlayerCharacter>();
	if (!IsValid(Owner))
	{
		return false;
	}

	if (Owner->IsMovingBackward())
	{
		return false;
	}

	return true;
}

void UHSprintComponent::ToggleSprint()
{
	UHStateManagerComponent* StateManagerComponent = GetOwnerStateManagerComponent();
	if (!IsValid(StateManagerComponent))
	{
		return;
	}

	if (!StateManagerComponent->HasActiveState(State_Movement_Sprinting))
	{
		StartSprint();
		return;
	}

	StopSprint();
}

void UHSprintComponent::StartSprint()
{
	if (!CanSprint())
	{
		return;
	}

	UCharacterMovementComponent* CMC = GetOwnerCharacterMovementComponent();
	if (!IsValid(CMC))
	{
		return;
	}

	UHStateManagerComponent* StateManagerComponent = GetOwnerStateManagerComponent();
	if (!IsValid(StateManagerComponent))
	{
		return;
	}

	DefaultSpeed = CMC->MaxWalkSpeed;
	CMC->MaxWalkSpeed = SprintSpeed;

	StateManagerComponent->ActivateState(State_Movement_Sprinting);
}

void UHSprintComponent::StopSprint()
{
	UCharacterMovementComponent* CMC = GetOwnerCharacterMovementComponent();
	if (!IsValid(CMC))
	{
		return;
	}

	UHStateManagerComponent* StateManagerComponent = GetOwnerStateManagerComponent();
	if (!IsValid(StateManagerComponent))
	{
		return;
	}

	CMC->MaxWalkSpeed = DefaultSpeed;
	StateManagerComponent->DeactivateState(State_Movement_Sprinting);
}


UCharacterMovementComponent* UHSprintComponent::GetOwnerCharacterMovementComponent()
{
	const ACharacter* Owner = GetOwner<ACharacter>();
	if (!IsValid(Owner))
	{
		return nullptr;
	}

	return Owner->GetComponentByClass<UCharacterMovementComponent>();
}

UHStateManagerComponent* UHSprintComponent::GetOwnerStateManagerComponent()
{
	const ACharacter* Owner = GetOwner<ACharacter>();
	if (!IsValid(Owner))
	{
		return nullptr;
	}

	return Owner->GetComponentByClass<UHStateManagerComponent>();
}
