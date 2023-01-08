// Fill out your copyright notice in the Description page of Project Settings.


#include "CrowProjectile.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ACrowProjectile::ACrowProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	//Assign the root as the capsule component
	crowMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Crow Projectile"));
	RootComponent = crowMesh;
	crowMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Crow Movements"));
	crowMovement->MaxSpeed = 1300.0f;
	crowMovement->InitialSpeed= 1300.0f;
}

// Called when the game starts or when spawned
void ACrowProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACrowProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

