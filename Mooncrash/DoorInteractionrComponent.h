// Yevhen Ustinchenko 2020

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "DoorInteractionrComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MOONCRASH_API UDoorInteractionrComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorInteractionrComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
	
private:
	UPROPERTY(EditAnywhere)
	float OpenDoorTargetYaw = 90.f;

	float StartYaw;

	UPROPERTY(EditAnywhere)
	float Speed = 1.f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* TriggerOpenDoor;

	UPROPERTY(EditAnywhere)
	AActor* ActorThatOpen;
		
};
