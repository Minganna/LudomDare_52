// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pawns/BasePawn.h"
#include "SoulCharacter.generated.h"

/**
 * 
 */
UCLASS()
class LD52_API ASoulCharacter : public ABasePawn
{
	GENERATED_BODY()
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	
	//pointer to the main character
	class AMainCharacter* character;
	//float that specify the visibility of the pawn
	UPROPERTY(EditDefaultsOnly, Category = "movement")
	float visibilityRange = 300.0f;
	// integer that allow the sould to move up and down
	int32 movementsUpDown = 1;
	//pointer to the top mesh of the pawn
	class UStaticMeshComponent* topMesh;
	//timer set to detect when the soul should disappear
	FTimerHandle disappearRateTimerHandle;
	//wait 2 seconds before the sould should disappear
	float timeTillDisappear = 1.0f;
	//function used to check if it is time to disappear
	void checkDisappearCondition();
	bool spottedPlayer = false;
};
