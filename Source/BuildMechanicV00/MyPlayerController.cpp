// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

void AMyPlayerController::OnPossess(APawn* aPawn) 
{
    // Call parent class' OnPossess
    Super::OnPossess(aPawn);


    // Try to cast the incoming pawn to both player and robot
    PlayerPawn = Cast<AMyPlayerPawn>(aPawn);
    ControlledRobotPawn = Cast<ARobotPawn>(aPawn);

    // Set the camera initially to be from the player's perspective
    this->SetViewTarget(PlayerPawn);

    // If we just possessed a PlayerPawn
    if(PlayerPawn)
    {
        GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Yellow, FString::Printf(TEXT("We got a player pawn!")));
        checkf(PlayerPawn, TEXT("Unable to get a reference to the PlayerPawn."));
        // For the sake of maintaining a permanent reference to the player for the SetViewTarget camera management
        PermanentPlayerPawn = PlayerPawn;

        // Obtain a reference to the enhanced input component
        EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
        checkf(EnhancedInputComponent, TEXT("Unable to get a reference to the EnhancedInputComponent."));

        // Get the local player subsystem
        UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
        checkf(InputSubsystem, TEXT("Unable to get a reference to the EnhancedInputLocalPlayerSubsystem."));

        // Wipe existing mappings, and add our mapping
        checkf(InputMappingContext, TEXT("InputMappingContext was not specified."));
        InputSubsystem->ClearAllMappings();
        InputSubsystem->AddMappingContext(InputMappingContext, 0);

        // Then bind the input only if a valid value was provided...(Robot was clicked)
        if(ActionPossessRobot)
        {
            // First param is the UInputAction you want to bind, second is type of triggering event to listen for,
            // third is reference to instance, and fourth is the function that gets called upon triggering
            EnhancedInputComponent->BindAction(ActionPossessRobot, ETriggerEvent::Triggered, this, &AMyPlayerController::HandlePossessRobot);
        }
    }
    else if(ControlledRobotPawn)
    {
        GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Yellow, FString::Printf(TEXT("We got a robot pawn!")));


        // This is where we start binding the robot inputs....

        // Ok so first, when the robot is possessed, we want it to lift a little off of the workbench and towards us...
        ControlledRobotPawn->RobotMoveComponent->RobotBuildModeFloat();

        if(ActionRobotPan)
        {

            // BIND IT
            EnhancedInputComponent->BindAction(ActionRobotPan, ETriggerEvent::Triggered, this, &AMyPlayerController::HandlePanRobot);

        }


    }
}

void AMyPlayerController::HandlePossessRobot()
{
    if(PlayerPawn)
    {
        // Ok this piece of code appears to be the key to ensuring that only the robot is clicked...
        // Next step is break this open and understand it a bit better
        // Structure containing information about one hit of a trace, such as point of impact and surface normal at that point.
        FHitResult HitResult;

        // ECollisionChannel TraceChannel, bool bTraceComplex, FHitResult & HitResult
        GetHitResultUnderCursor(ECollisionChannel::ECC_Pawn, false, HitResult);

        // If what was clicked was a robot mesh....
        if (HitResult.GetComponent()->GetName() == "RobotMesh")
        {
            // switch possession over to robot....

            // GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString::Printf(TEXT("Mouse Click+++ Component: %s"), *HitResult.GetComponent()->GetName()) );

            GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Yellow, FString::Printf(TEXT("Robot was clicked!")));

            // CurrentController = PlayerPawn->GetController();
            // checkf(CurrentController, TEXT("Unable to get a reference to the CurrentController."))

            // Grab a reference to the robot on the workbench
            AActor* RobotPawn = UGameplayStatics::GetActorOfClass(GetWorld(), ARobotPawn::StaticClass());
            checkf(RobotPawn, TEXT("Unable to get a reference to the RobotPawn."));
            // RobotPawn = Cast<ARobotPawn>(RobotPawn);
            // And then take possession of it
            this->Possess(Cast<ARobotPawn>(RobotPawn));
            this->SetViewTarget(PermanentPlayerPawn);
            // this->SetViewTargetWithBlend(Cast<AMyPlayerPawn>(PlayerPawn), 2.f);
        }
    }
}

void AMyPlayerController::HandlePanRobot(const FInputActionValue& InputActionValue){

    // Value is a Vector2D
    const FVector2D MouseCoord = InputActionValue.Get<FVector2D>();

    GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Yellow, FString::Printf(TEXT("Mouse X: %f, Mouse Y: %f"), MouseCoord.X, MouseCoord.Y));

}

void AMyPlayerController::OnUnPossess()
{
    // Unbind things here...
    // EnhancedInputComponent->ClearActionBindings();

    // Call the parent class' OnUnPossess
    Super::OnUnPossess();
}