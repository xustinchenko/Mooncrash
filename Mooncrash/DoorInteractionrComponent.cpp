// Yevhen Ustinchenko 2020

#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "DoorInteractionrComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Actor.h"
float GlobalDeltaTime;
// Sets default values for this component's properties
UDoorInteractionrComponent::UDoorInteractionrComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorInteractionrComponent::BeginPlay()
{
	Super::BeginPlay();
	OpenDoorTargetYaw += GetOwner()->GetActorRotation().Yaw;
	ActorThatOpen = GetWorld()->GetFirstPlayerController()->GetPawn();
	StartYaw = GetOwner()->GetActorRotation().Yaw;
	UserInput = GetOwner()->FindComponentByClass<UInputComponent>();		
}


// Called every frame
void UDoorInteractionrComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	GlobalDeltaTime = DeltaTime;
	if(TriggerOpenDoor->IsOverlappingActor(ActorThatOpen))
	{
		OpenDoor(GlobalDeltaTime);
		if(UserInput){
			UE_LOG(LogTemp, Warning, TEXT("CAN INTERACT"));
			UserInput->BindAction("Interact", IE_Pressed,this, &UDoorInteractionrComponent::OpenDoor);
			UE_LOG(LogTemp, Warning, TEXT("PREESSS"));

		}
	}
	else
	{
		CloseDoor(DeltaTime);
	}
	// ...
}

void UDoorInteractionrComponent::OpenDoor(float DeltaTime)
{
	FRotator OpenDoor = GetOwner()->GetActorRotation();
	OpenDoor.Yaw = FMath::Lerp(OpenDoor.Yaw,OpenDoorTargetYaw,DeltaTime*Speed);
	GetOwner()->SetActorRotation(OpenDoor);
	// ...
}

void UDoorInteractionrComponent::OpenDoor()
{
	OpenDoor(GlobalDeltaTime);
}

void UDoorInteractionrComponent::CloseDoor(float DeltaTime)
{
	FRotator OpenDoor = GetOwner()->GetActorRotation();
	OpenDoor.Yaw = FMath::Lerp(OpenDoor.Yaw,StartYaw,DeltaTime*Speed);
	GetOwner()->SetActorRotation(OpenDoor);
	// ...
}

