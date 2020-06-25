// Yevhen Ustinchenko 2020

#pragma once

#include "Engine/World.h"
#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MOONCRASH_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	ATank* GetControllerTank() const;
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation);
	bool GetLookDirection(FVector2D ScreenLocation,FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection,FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;
};
