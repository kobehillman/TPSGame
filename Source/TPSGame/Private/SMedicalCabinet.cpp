// Fill out your copyright notice in the Description page of Project Settings.


#include "SMedicalCabinet.h"

// Sets default values
ASMedicalCabinet::ASMedicalCabinet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	RootComponent = BaseMesh;

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>("DoorMesh");
	DoorMesh->SetupAttachment(BaseMesh);


}




// Called when the game starts or when spawned
void ASMedicalCabinet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASMedicalCabinet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

