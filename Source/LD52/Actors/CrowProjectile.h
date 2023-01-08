// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CrowProjectile.generated.h"

UCLASS()
class LD52_API ACrowProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACrowProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//the mesh of the crow
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* crowMesh;
	//component used to determine the spawning and maximum speed to the crow
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movements", meta = (AllowPrivateAccess = "true"))
	class UProjectileMovementComponent* crowMovement;

};
