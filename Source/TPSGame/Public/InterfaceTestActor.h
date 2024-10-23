// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractInterface.h"
#include "GameFramework/Actor.h"
#include "InterfaceTestActor.generated.h"

class UStaticMeshComponent;

UCLASS()
class TPSGAME_API AInterfaceTestActor : public AActor, public IInteractInterface
{
	GENERATED_BODY()

	
	
public:

	
	// Sets default values for this actor's properties
	AInterfaceTestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditInstanceOnly, Category = "Test Actor")
	FInteractableData InstanceInteractableData;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void BeginFocus() override;
	virtual void EndFocus() override;
	virtual void BeginInteract() override;
	virtual void EndInteract() override;
	virtual void Interact(ASCharacter* PlayerCharacter) override;
};
