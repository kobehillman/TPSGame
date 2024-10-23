// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionWidget.h"
#include "MainMenu.h"
#include "GameFramework/HUD.h"
#include "CharacterHUD.generated.h"

/**
 * 
 */
UCLASS()
class TPSGAME_API ACharacterHUD : public AHUD
{
	GENERATED_BODY()


public:

	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<UMainMenu> MainMenuClass;

	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<UInteractionWidget> InteractionWidgetClass;

	bool bIsMenuVisible;

	ACharacterHUD();

	void DisplayMenu();
	void HideMenu();

	void ShowInteractionWidget() const;
	void HideInteractionWidget() const;
	void UpdateInteractionWidget(const FInteractableData* InteractableData) const;

protected:
	

	UPROPERTY()
	UMainMenu* MainMenuWidget;

	UPROPERTY()
	UInteractionWidget* InteractionWidget;
	
	
	virtual void BeginPlay() override;
};
