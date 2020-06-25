// Yevhen Ustinchenko 2020


#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
    RelativeSpeed = FMath::Clamp<float>(RelativeSpeed,-1,1);
    auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    auto RawNewElevation = RelativeRotation.Yaw + ElevationChange;
    //UE_LOG(LogTemp, Warning, TEXT("AimingTurret: %f  %f"),RelativeRotation.Yaw, RawNewElevation);
    SetRelativeRotation(FRotator(0,RawNewElevation,0));
}
