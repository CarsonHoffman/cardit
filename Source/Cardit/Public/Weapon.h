// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SceneComponent.h"
#include "Weapon.generated.h"

class ACarditCharacter;

UCLASS( Blueprintable, meta=(BlueprintSpawnableComponent) )
class CARDIT_API UWeapon : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeapon();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void Fire();

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxRangeInCm = 5000.f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int DamagePerShot = 20;


};
