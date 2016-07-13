// Fill out your copyright notice in the Description page of Project Settings.

#include "Cardit.h"
#include "CarditPlayerController.h"
#include "UnrealNetwork.h"
#include "CarditCharacter.h"
#include "CarditWeapon.h"

void ACarditPlayerController::FireCurrentWeapon()
{
	Cast<ACarditCharacter>(GetPawn())->GetCurrentWeapon()->Fire();
}
