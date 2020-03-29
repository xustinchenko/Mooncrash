// Yevhen Ustinchenko 2020

#include "Engine/World.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* PlayerTank = GetPalyerTank();
	if(!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller can't find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller find player: %s"), *(PlayerTank->GetName()));
	}
	
}

ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
} 

ATank* ATankAIController::GetPalyerTank() const
{
    return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}