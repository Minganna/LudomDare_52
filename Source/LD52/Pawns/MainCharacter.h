// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pawns/BasePawn.h"
#include "MainCharacter.generated.h"

/**
 * 
 */
UCLASS()
class LD52_API AMainCharacter : public ABasePawn
{
	GENERATED_BODY()
public:
	AMainCharacter();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	//component used to attach the camera to the character
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* springArm;
	//the main camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* mainCamera;
	//variable used to determine speed
	UPROPERTY(EditAnywhere, Category = "movement")
	float speed = 400.0f;
	//Used to make the character swinging up and dowm
	UPROPERTY(EditAnywhere, Category = "movement")
	float turnRatePitch = 400.0f;
	//Used to turn the character and move around
	UPROPERTY(EditAnywhere, Category = "movement")
	float turnRateYaw = 45.0f;
	//pointer to the player controller
	APlayerController* playerControllerRef;

	//function used to move the character
	void move(float value);
	//function used to turn the character
	void turn(float value);

	//function to fire the crow
	void fire();

public: 
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
