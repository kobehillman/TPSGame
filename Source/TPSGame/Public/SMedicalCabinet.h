// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SGameplayInterface.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SMedicalCabinet.generated.h"


UCLASS()
class TPSGAME_API ASMedicalCabinet : public AActor, public ISGameplayInterface
{
	GENERATED_BODY()


public:	
	// Sets default values for this actor's properties
	ASMedicalCabinet();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* DoorMesh;


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
