// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "Cardit.h"
#include "CarditCharacter.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/InputSettings.h"
#include "UnrealNetwork.h"

DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

//////////////////////////////////////////////////////////////////////////
// ATempCPPShooterCharacter

ACarditCharacter::ACarditCharacter()
{
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;
}

void ACarditCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

}

void ACarditCharacter::Initialize(UCameraComponent* CameraToSet, UCarditWeapon* WeaponToSet)
{
	Camera = CameraToSet;
	CurrentWeapon = WeaponToSet;
}

//////////////////////////////////////////////////////////////////////////
// Input

void ACarditCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	
}

void ACarditCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void ACarditCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void ACarditCharacter::CharStartJumping()
{
	Jump();
}

void ACarditCharacter::CharStopJumping()
{
	StopJumping();
}

void ACarditCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ACarditCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

int ACarditCharacter::GetHealth()
{
	return Health;
}

void ACarditCharacter::DealDamage(int Damage)
{
	Health -= Damage;
}

void ACarditCharacter::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ACarditCharacter, Health);
}

