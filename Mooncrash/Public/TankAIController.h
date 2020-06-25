// Yevhen Ustinchenko 2020

#pragma once

#include "Engine/World.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class MOONCRASH_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void AimPlayer();

	ATank* GetControlledTank() const;
	ATank* GetPalyerTank() const;
	
};
