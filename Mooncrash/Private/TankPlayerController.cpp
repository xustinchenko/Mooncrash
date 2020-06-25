// Yevhen Ustinchenko 2020


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* ControlledTank = GetControllerTank();
	if(!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller possesing: %s"), *(ControlledTank->GetName()));
	}
	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
    if(!GetControllerTank()) return;

    FVector HitLocation;
    if(GetSightRayHitLocation(HitLocation))
	{
		GetControllerTank()->AimAt(HitLocation);
	} 
	
   // UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation)
{
    int32 ViewportSizeX,ViewportSizeY;
    GetViewportSize(ViewportSizeX,ViewportSizeY);
    auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation,ViewportSizeY * CrosshairYLocation);

	FVector LookDirection;
	if(GetLookDirection(ScreenLocation,LookDirection))
	{	
		GetLookVectorHitLocation(LookDirection,HitLocation);
	}
    return true;
}


bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation,FVector& LookDirection) const
{
	FVector CameraWorldLocation;	
	return DeprojectScreenPositionToWorld(ScreenLocation.X,ScreenLocation.Y,CameraWorldLocation,LookDirection);		
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection,FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if(GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
		))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}

ATank* ATankPlayerController::GetControllerTank() const
{
    return Cast<ATank>(GetPawn());
}