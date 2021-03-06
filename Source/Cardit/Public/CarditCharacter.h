// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "CarditCharacter.generated.h"

class UInputComponent;
class UCarditWeapon;

UCLASS(config = Game)
class ACarditCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ACarditCharacter();

	virtual void BeginPlay();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles stafing movement, left and right */
	void MoveRight(float Val);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void CharStartJumping();

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void CharStopJumping();

	/**
	* Called via input to turn at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void TurnAtRate(float Rate);

	/**
	* Called via input to turn look up/down at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void LookUpAtRate(float Rate);

	UFUNCTION(BlueprintCallable, Category = "Character Variables")
	int GetHealth();

	void GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const;

	UCameraComponent* GetCamera() { return Camera; }
	UCarditWeapon* GetCurrentWeapon() { return CurrentWeapon; }

	void DealDamage(int Damage);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End of APawn interface

	UPROPERTY(EditDefaultsOnly, Replicated, Category = "Setup")
	int Health = 100;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UCameraComponent* CameraToSet, UCarditWeapon* WeaponToSet);

	UCameraComponent* Camera = nullptr;
	UCarditWeapon* CurrentWeapon;
};

