// Fill out your copyright notice in the Description page of Project Settings.


#include "SMedCabinet.h"

// Sets default values
ASMedCabinet::ASMedCabinet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	RootComponent = BaseMesh;

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	DoorMesh->SetupAttachment(BaseMesh);
	
	TargetYaw = 130;
}


void ASMedCabinet::Interact_Implementation(APawn* InstigatorPawn)
{
	DoorMesh->SetRelativeRotation(FRotator(0, TargetYaw, 0));
}


// Called when the game starts or when spawned
void ASMedCabinet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASMedCabinet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

