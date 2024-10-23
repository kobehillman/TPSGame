// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractInterface.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

class UItemBase;
class UDataTable;

UCLASS()
class TPSGAME_API APickup : public AActor, public IInteractInterface
{
	GENERATED_BODY()

	
public:
	
	APickup();

	void InitializePickup(const TSubclassOf<UItemBase> BaseClass, const int32 InQuantity);

	void InitializeDrop(UItemBase* ItemToDrop, int32 InQuantity);
	
	FORCEINLINE UItemBase* GetItemData(){ return ItemReference; };
	
	virtual void BeginFocus() override;
	virtual void EndFocus() override;
	


	

protected:

	UPROPERTY(VisibleAnywhere, category = "Pickup | Components")
	UStaticMeshComponent* PickupMesh;

	UPROPERTY(EditInstanceOnly, category = "Pickup | Item Initialization")
	UDataTable* ItemDataTable;

	UPROPERTY(EditInstanceOnly, category = "Pickup | Item Initialization")
	FName DesiredItemID;

	UPROPERTY(VisibleAnywhere, category = "Pickup | Item Reference")
	UItemBase* ItemReference;
	
	UPROPERTY(EditInstanceOnly, category = "Pickup | Item Initialization")
	int32 ItemQuantity;

	UPROPERTY(VisibleInstanceOnly, category = "Pickup | Interaction")
	FInteractableData InstanceInteractableData;
	
	virtual void BeginPlay() override;
	
	virtual void Interact(ASCharacter* PlayerCharacter) override;
	void UpdateInteractableData();
	
	void TakePickup(const ASCharacter* Taker);

	
#if WITH_EDITOR	
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif	
};
