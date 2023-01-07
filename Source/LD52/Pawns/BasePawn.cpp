// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Create the capsule component
	capsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule component"));
	//Assign the root as the capsule component
	RootComponent = capsuleComp;

	//Create the base mesh
	baseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bottom Part"));
	baseMesh->SetupAttachment(capsuleComp);
	//Create the TopPart of the mesh
	topMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Top Part"));
	topMesh->SetupAttachment(baseMesh);
	//Create the spawning point
	projectileSpawn = CreateDefaultSubobject<USceneComponent>(TEXT("Spawning point"));
	projectileSpawn->SetupAttachment(topMesh);

}

// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

