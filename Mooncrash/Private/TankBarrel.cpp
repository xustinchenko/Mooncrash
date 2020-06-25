// Yevhen Ustinchenko 2020


#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
    RelativeSpeed = FMath::Clamp<float>(RelativeSpeed,-1,1);
    auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    auto RawNewElevation = RelativeRotation.Roll - ElevationChange;
    SetRelativeRotation(FRotator(0,0,FMath::Clamp<float>(RawNewElevation,MinElevationDegrees,MaxElevationDegrees)));
}
