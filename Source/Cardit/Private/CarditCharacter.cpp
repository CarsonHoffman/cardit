// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "Cardit.h"
#include "CarditCharacter.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/InputSettings.h"

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

//////////////////////////////////////////////////////////////////////////
// Input

void ACarditCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// set up gameplay key bindings
	check(InputComponent);

	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	InputComponent->BindAxis("MoveForward", this, &ACarditCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ACarditCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &ACarditCharacter::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &ACarditCharacter::LookUpAtRate);
}

void ACarditCharacter::OnFire()
{
	/* PROJECTILE CODE (UNUSED) */
// 	try and fire a projectile
// 		if (ProjectileClass != NULL)
// 		{
// 			const FRotator SpawnRotation = GetControlRotation();
// 			// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
// 			const FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);
// 	
// 			UWorld* const World = GetWorld();
// 			if (World != NULL)
// 			{
// 				// spawn the projectile at the muzzle
// 				World->SpawnActor<ATempCPPShooterProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);
// 			}
// 		}

	/* SOUND CODE (UNUSED) */
// 	// try and play the sound if specified
// 	if (FireSound != NULL)
// 	{
// 		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
// 	}
// 
// 	// try and play a firing animation if specified
// 	if (FireAnimation != NULL)
// 	{
// 		// Get the animation object for the arms mesh
// 		UAnimInstance* AnimInstance = Mesh1P->GetAnimInstance();
// 		if (AnimInstance != NULL)
// 		{
// 			AnimInstance->Montage_Play(FireAnimation, 1.f);
// 		}
// 	}

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