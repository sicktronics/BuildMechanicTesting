// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"
#include "InputMappingContext.h"
#include "MyPlayerPawn.h"
#include "RobotPawn.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class BUILDMECHANICV00_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// The Input Action to map to possessing the robot
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Player Input|Pawn Movement")
	UInputAction* ActionPossessRobot = nullptr;

	// The Input Action to map to panning over the robot
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Player Input|Pawn Movement")
	UInputAction* ActionRobotPan = nullptr;

	// The Input Action to map to orbiting the robot
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Player Input|Pawn Movement")
	UInputAction* ActionRobotOrbit = nullptr;

	// The Input Action to map to zooming into the robot
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Player Input|Pawn Movement")
	UInputAction* ActionRobotZoom = nullptr;

	// The Input Mapping Context to use
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Player Input|Pawn Movement")
	TObjectPtr<UInputMappingContext> InputMappingContext = nullptr;

protected:
	virtual void OnPossess(APawn* aPawn) override;
	virtual void OnUnPossess() override;

	void HandlePossessRobot();
	void HandlePanRobot(const FInputActionValue& InputActionValue);


private:
	// Used to store the InputComponent cast to an EnhancedInputComponent
	UPROPERTY()
	UEnhancedInputComponent* EnhancedInputComponent = nullptr;

	// Used to store a reference to the pawn we are controlling
	UPROPERTY()
	AMyPlayerPawn* PlayerPawn = nullptr;

	UPROPERTY()
	AMyPlayerPawn* PermanentPlayerPawn = nullptr;

	// The robot pawn that we are controlling
	UPROPERTY()
	ARobotPawn* ControlledRobotPawn = nullptr;

	// Cache a reference to the current controller
	UPROPERTY()
	AController* CurrentController = nullptr;

	
};
