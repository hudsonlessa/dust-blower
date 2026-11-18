// Fill out your copyright notice in the Description page of Project Settings.


#include "DustBlower/Public/Player/HPlayerCharacter.h"

#include "EnhancedInputComponent.h"


// Sets default values
AHPlayerCharacter::AHPlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

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
}

void AHPlayerCharacter::HandleMove(const FInputActionInstance& ActionInstance)
{
	FRotator ControlRotation = GetControlRotation();
	ControlRotation.Pitch = 0.0f;
	ControlRotation.Roll = 0.0f;

	const FInputActionValue ActionValue = ActionInstance.GetValue();
	const FVector2D AxisValue = ActionValue.Get<FVector2D>();

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
