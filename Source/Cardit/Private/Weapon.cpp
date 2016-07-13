// Fill out your copyright notice in the Description page of Project Settings.

#include "Cardit.h"
#include "Weapon.h"
#include "CarditCharacter.h"
#include "UnrealNetwork.h"

// Sets default values for this component's properties
UWeapon::UWeapon()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWeapon::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UWeapon::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UWeapon::Fire()
{
	auto Camera = Cast<ACarditCharacter>(GetOwner())->GetCamera();
	DrawDebugLine(GetWorld(), Camera->GetComponentLocation(), Camera->GetComponentLocation() + (Camera->GetComponentRotation().Vector() * MaxRangeInCm), FColor(255, 0, 0), false, 5.f, 0, 2.5f);
	UE_LOG(LogTemp, Warning, TEXT("Fired"));
}

