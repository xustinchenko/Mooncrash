// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "OpenDoor.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();	
	OpenDoorTargetYaw += GetOwner()->GetActorRotation().Yaw;
	ActorThatOpen = GetWorld()->GetFirstPlayerController()->GetPawn();
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(TriggerOpenDoor->IsOverlappingActor(ActorThatOpen))
	{
		OpenDoor(DeltaTime);
	}
	// ...
}

void UOpenDoor::OpenDoor(float DeltaTime)
{
	FRotator OpenDoor = GetOwner()->GetActorRotation();
	OpenDoor.Yaw = FMath::Lerp(OpenDoor.Yaw,OpenDoorTargetYaw,DeltaTime*Speed);
	GetOwner()->SetActorRotation(OpenDoor);
	// ...
}

