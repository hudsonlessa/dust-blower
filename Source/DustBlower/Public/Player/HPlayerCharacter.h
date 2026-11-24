// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HPlayerCharacter.generated.h"

struct FInputActionValue;
struct FInputActionInstance;
class UInputAction;

UCLASS()
class DUSTBLOWER_API AHPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputAction> Input_Move;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputAction> Input_Look;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputAction> Input_Jump;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputAction> Input_Sprint;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputAction> Input_Crouch;

	void HandleMove(const FInputActionInstance& ActionInstance);

	void HandleLook(const FInputActionValue& ActionValue);

	void HandleJump();

	void HandleSprint();

	void HandleCrouch();
};
