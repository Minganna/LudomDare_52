// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "GameFramework/GameStateBase.h"
#include "Engine/World.h"

void ALobbyGameMode::PostLogin(APlayerController* newPlayer)
{
	Super::PostLogin(newPlayer);
	if (!GameState) 
	{
		return;
	}
	int32 numberOfPlayers = GameState->PlayerArray.Num();
	if (numberOfPlayers == 2)
	{
		UWorld* world = GetWorld();
		if (world)
		{
			bUseSeamlessTravel = true;
			world->ServerTravel(FString(TEXT("/Game/Maps/GameLevel1?listen")));
		}
	}
}