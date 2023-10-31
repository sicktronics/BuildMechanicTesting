// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveComponent.h"

// Sets default values for this component's properties
UMoveComponent::UMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

}

// Called when the game starts
void UMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	// Set start location

	// Compute normalized movement
	// MoveOffsetNorm = MoveOffset;
	// MoveOffsetNorm.Normalize();


	// EndRelativeLocation = StartRelativeLocation;
	// EndRelativeLocation += MoveOffset;

	// RobotBuildModeFloat();
	
}

// Try creating a function and then calling it once possesion is gathered?
void UMoveComponent::RobotBuildModeFloat(){
	// GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Yellow, FString::Printf(TEXT("Movement called!")));

	StartRelativeLocation = GetRelativeLocation();
	SetRelativeLocation(StartRelativeLocation + MoveOffset);

}

// Called every frame
void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// CurDist += DeltaTime * Speed;
	// SetRelativeLocation(StartRelativeLocation + MoveOffset);
	// GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Yellow, FString::Printf(TEXT("Movement called!")));
	// Compute and set current location
}

