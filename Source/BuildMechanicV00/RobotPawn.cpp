// Fill out your copyright notice in the Description page of Project Settings.


#include "RobotPawn.h"

// Sets default values
ARobotPawn::ARobotPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set up components

	RobotMoveComponent = CreateDefaultSubobject<UMoveComponent>(TEXT("RobotMoveComponent"));
	RootComponent = RobotMoveComponent;
	RobotMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RobotMesh"));
	RobotMesh->SetupAttachment(RootComponent);


	
	// RobotMoveComponent->AttachToComponent(this->GetRootComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}

// Called when the game starts or when spawned
void ARobotPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARobotPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARobotPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

