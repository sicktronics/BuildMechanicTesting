// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/DefaultPawn.h"
#include "MyPlayerPawn.h"
#include "BuildMechanicV00GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class BUILDMECHANICV00_API ABuildMechanicV00GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	// Overriding this so we can set the default pawn class before the game starts
	void InitGameState() override;

private:
	// Ensuring that the default pawn is some type of MyPlayerPawn
	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<AMyPlayerPawn> CustomMyPlayerPawnClass = AMyPlayerPawn::StaticClass();
	
};
