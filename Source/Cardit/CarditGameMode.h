// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "CarditGameMode.generated.h"

class ACarditCharacter;

/**
 * 
 */
UCLASS()
class CARDIT_API ACarditGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:

	UFUNCTION(Server, Reliable, WithValidation)
	void DealDamageOntoCharacter(ACarditCharacter* CharToHit, int Damage);
	void DealDamageOntoCharacter_Implementation(ACarditCharacter* CharToHit, int Damage);
	bool DealDamageOntoCharacter_Validate(ACarditCharacter* CharToHit, int Damage);
	
	
};
