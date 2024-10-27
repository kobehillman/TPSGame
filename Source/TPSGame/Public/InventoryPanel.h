// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItemSlot.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/WrapBox.h"
#include "InventoryPanel.generated.h"

class UInventoryComponent;
class ASCharacter;


UCLASS()
class TPSGAME_API UInventoryPanel : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void RefreshInventory();
	UPROPERTY(meta=(BindWidget))
	UWrapBox* InventoryPanel;
	UPROPERTY(meta=(BindWidget))
	UTextBlock* WeightInfo;
	UPROPERTY(meta=(BindWidget))
	UTextBlock* CapacityInfo;
	UPROPERTY()
	ASCharacter* PlayerCharacter;
	UPROPERTY()
	UInventoryComponent* InventoryReference;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UInventoryItemSlot> InventorySlotClass;


protected:

	void SetInfoText() const;
	virtual void NativeOnInitialized() override;
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent,
		UDragDropOperation* InOperation) override;
	
};
