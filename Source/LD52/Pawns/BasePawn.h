// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

// Main class that will have AI and player classes devire from, includes the main functionalities
UCLASS()
class LD52_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

protected:
	void rotateBust(FVector lookAtTarget);
	//getter for the topMesh
	UStaticMeshComponent* getTopMesh();
	//getter of the projectile spawn location 
	FVector getProjectileSpawnPoint();


private:
	//components below are constructed in the class constructor
	//component used to handle collision, will replace the root component, forward declared in header file to avoid including a class that will not be used in header
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* capsuleComp;
	//Empty mesh used for movements
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* movementsMesh;

	//mesh of the base of the pawn
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* baseMesh;
	//top part of the mesh of the pawn
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* topMesh;
	//transform location where the projectile will spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* projectileSpawn;

};
