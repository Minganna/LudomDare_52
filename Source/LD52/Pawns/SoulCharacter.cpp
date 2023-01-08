// Fill out your copyright notice in the Description page of Project Settings.


#include "SoulCharacter.h"
#include "MainCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
// Called every frame
void ASoulCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//set the location towards the pawn should move to zero vector
	FVector deltaLocation(0.0f);
	// collect the input from the player and move towards or backwards depending on the input, the front axes is X so we modify x
	if(GetActorLocation().Z > 140)
	{
		movementsUpDown = -1;

	}
	if(GetActorLocation().Z < 128)
	{
		movementsUpDown = 1;
	}
	deltaLocation.Z = movementsUpDown * 20.0f * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalOffset(deltaLocation, true);


	if (character)
	{
		//Find distance to main character
		float distance = FVector::Dist(GetActorLocation(), character->GetActorLocation());
		//if in range, rotate turret towards character
		if (distance <= visibilityRange)
		{
			rotateBust(character->GetActorLocation());
		}
	}




}

void ASoulCharacter::BeginPlay()
{
	Super::BeginPlay();

	character = Cast<AMainCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	topMesh = getTopMesh();
}
