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
	//float that specify the 
	UPROPERTY(EditDefaultsOnly, Category = "movement")
	float visibilityRange = 300.0f;
	int32 movementsUpDown = 1;
	class UStaticMeshComponent* topMesh;
};
