// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "../Actors/CrowProjectile.h"

AMainCharacter::AMainCharacter()
{
	//Create the spring arm and attach it to the capsule collider
	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	springArm->SetupAttachment(RootComponent);
	//Create the Camera and attach it to the spring arm
	mainCamera = CreateDefaultSubobject <UCameraComponent>(TEXT("Main Camera"));
	mainCamera->SetupAttachment(springArm);
}

void AMainCharacter::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//bind the player move forwards input to the move function
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMainCharacter::move);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AMainCharacter::turn);
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &AMainCharacter::fire);

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	//convert the player controller to player controller to access mouse detection functions
	playerControllerRef = Cast<APlayerController>(GetController());

}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (playerControllerRef)
	{
		//check where the cursor is located
		FHitResult hitResult;
		playerControllerRef->GetHitResultUnderCursor(
			ECollisionChannel::ECC_Visibility,
			false,
			hitResult);
		//call function from base pawn to rotate the bust
		rotateBust(hitResult.ImpactPoint);

	}

}

void AMainCharacter::move(float value)
{
	//set the location towards the pawn should move to zero vector
	FVector deltaLocation(0.0f);
	// collect the input from the player and move towards or backwards depending on the input, the front axes is X so we modify x
	deltaLocation.X = value * speed * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalOffset(deltaLocation,true);
}

void AMainCharacter::turn(float value)
{
	//initialise a zero rotator
	FRotator deltaRotator= FRotator::ZeroRotator;
	deltaRotator.Yaw= value * turnRateYaw * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalRotation(deltaRotator,true);


}

void AMainCharacter::fire()
{
	FVector projectileSpawnLocation=getProjectileSpawnPoint();
	FRotator projectSpawnRotation = getProjectileRotationPoint();
	UWorld* world = GetWorld();
	if (world)
	{
		world->SpawnActor<ACrowProjectile>(crowProjectiles,projectileSpawnLocation, projectSpawnRotation);
	}
}



