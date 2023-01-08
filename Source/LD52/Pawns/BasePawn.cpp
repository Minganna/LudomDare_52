// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Create the capsule component
	capsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule component"));
	//Assign the root as the capsule component
	RootComponent = capsuleComp;
	movementsMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Movements Part"));
	movementsMesh->SetupAttachment(capsuleComp);
	//Create the base mesh
	baseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bottom Part"));
	baseMesh->SetupAttachment(movementsMesh);
	//Create the TopPart of the mesh
	topMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Top Part"));
	topMesh->SetupAttachment(baseMesh);
	//Create the spawning point
	projectileSpawn = CreateDefaultSubobject<USceneComponent>(TEXT("Spawning point"));
	projectileSpawn->SetupAttachment(topMesh);
}


void ABasePawn::rotateBust(FVector lookAtTarget)
{
	//check where the character should look at by substracting the position of the mouse to the current pos
	FVector toTarget = lookAtTarget - topMesh->GetComponentLocation();
	FVector forward = lookAtTarget - GetActorForwardVector();
	//convert the vector to rotation
	FRotator lookRotation = FRotator(0.0f, toTarget.Rotation().Yaw, 0.0f);
	FRotator forwardRotation= FRotator(0.0f, forward.Rotation().Yaw, 0.0f);

	topMesh->SetWorldRotation(
			FMath::RInterpTo(topMesh->GetComponentRotation(),
			lookRotation,
			UGameplayStatics::GetWorldDeltaSeconds(this),
			25.0f));

}

UStaticMeshComponent * ABasePawn::getTopMesh()
{
	if (topMesh)
	{
		return topMesh;
	}
	return nullptr;
}

FVector ABasePawn::getProjectileSpawnPoint()
{
	return projectileSpawn->GetComponentLocation();
}

FRotator ABasePawn::getProjectileRotationPoint()
{
	return projectileSpawn->GetComponentRotation();
}




