// Fill out your copyright notice in the Description page of Project Settings.


#include "DustBlower/Public/Player/HPlayerCharacter.h"

#include "EnhancedInputComponent.h"
#include "HGameplayTags.h"
#include "ActionCommandSystem/HActionCommandSystemComponent.h"


// Called to bind functionality to input
void AHPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);

	if (ensure(Input_Move))
	{
		EIC->BindAction(Input_Move, ETriggerEvent::Triggered, this, &AHPlayerCharacter::HandleMove);
	}

	if (ensure(Input_Look))
	{
		EIC->BindAction(Input_Look, ETriggerEvent::Triggered, this, &AHPlayerCharacter::HandleLook);
	}

	if (ensure(Input_Jump))
	{
		EIC->BindAction(Input_Jump, ETriggerEvent::Triggered, this, &AHPlayerCharacter::HandleJump);
	}

	if (ensure(Input_Sprint))
	{
		EIC->BindAction(Input_Sprint, ETriggerEvent::Started, this, &AHPlayerCharacter::HandleSprint);
	}

	if (ensure(Input_Crouch))
	{
		EIC->BindAction(Input_Crouch, ETriggerEvent::Started, this, &AHPlayerCharacter::HandleCrouch);
	}
}

void AHPlayerCharacter::HandleMove(const FInputActionInstance& ActionInstance)
{
	FRotator ControlRotation = GetControlRotation();
	ControlRotation.Pitch = 0.0f;
	ControlRotation.Roll = 0.0f;

	const FInputActionValue ActionValue = ActionInstance.GetValue();
	const FVector2D AxisValue = ActionValue.Get<FVector2D>();

	UHActionCommandSystemComponent* ACSC = GetComponentByClass<UHActionCommandSystemComponent>();
	if (IsValid(ACSC) && AxisValue.X < 0.0f)
	{
		ACSC->UndoActionCommand(Command_Action_Movement_Sprint);
	}

	AddMovementInput(ControlRotation.Vector(), AxisValue.X);

	const FVector RightVector = ControlRotation.RotateVector(FVector::RightVector);
	AddMovementInput(RightVector, AxisValue.Y);
}

void AHPlayerCharacter::HandleLook(const FInputActionValue& ActionValue)
{
	const FVector2D Value = ActionValue.Get<FVector2D>();
	AddControllerYawInput(Value.X);
	AddControllerPitchInput(Value.Y);
}

void AHPlayerCharacter::HandleJump()
{
	Jump();
}

void AHPlayerCharacter::HandleSprint()
{
	UHActionCommandSystemComponent* ACSC = GetComponentByClass<UHActionCommandSystemComponent>();
	if (!IsValid(ACSC))
	{
		return;
	}

	ACSC->ExecuteActionCommand(Command_Action_Movement_Sprint);
}

void AHPlayerCharacter::HandleCrouch()
{
	if (!bIsCrouched)
	{
		Crouch();
		return;
	}

	UnCrouch();
}
