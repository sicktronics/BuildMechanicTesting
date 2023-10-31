// Copyright Epic Games, Inc. All Rights Reserved.


#include "BuildMechanicV00GameModeBase.h"

void ABuildMechanicV00GameModeBase::InitGameState()
{
    Super::InitGameState();

    // Set the default pawn

    // Check for no hard override
    if(DefaultPawnClass == ADefaultPawn::StaticClass())
    {
        // Set the default pawn (assignable on the BP end)
        DefaultPawnClass = CustomMyPlayerPawnClass;
    }
}