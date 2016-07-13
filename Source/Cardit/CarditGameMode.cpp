// Fill out your copyright notice in the Description page of Project Settings.

#include "Cardit.h"
#include "CarditGameMode.h"
#include "UnrealNetwork.h"
#include "CarditCharacter.h"


void ACarditGameMode::DealDamageOntoCharacter_Implementation(ACarditCharacter* CharToHit, int Damage)
{
	if (!CharToHit) { return; }

	CharToHit->DealDamage(Damage);
}

bool ACarditGameMode::DealDamageOntoCharacter_Validate(ACarditCharacter* CharToHit, int Damage)
{
	return true;
}