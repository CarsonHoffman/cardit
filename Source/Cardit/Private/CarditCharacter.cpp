// Fill out your copyright notice in the Description page of Project Settings.

#include "Cardit.h"
#include "CarditCharacter.h"


// Sets default values
ACarditCharacter::ACarditCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACarditCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACarditCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	AddMovementInput();
}

// Called to bind functionality to input
void ACarditCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

