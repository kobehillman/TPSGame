// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "GameFramework/Character.h"
#include "InteractInterface.h"
#include "SCharacter.generated.h"


class UInventoryComponent;
class UCameraComponent;
class USpringArmComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class UAnimMontage;
class USAttributeComponent;
class USInteractionComponent;
class UParticleSystem;
class ACharacterHUD;

USTRUCT()
struct FInteractionData
{
	GENERATED_USTRUCT_BODY()

	FInteractionData() : CurrentInteractable(nullptr), LastInteractionCheckTime(0.0f)
	{
		
	}

	UPROPERTY()
	AActor* CurrentInteractable;

	UPROPERTY()
	float LastInteractionCheckTime;
};

UCLASS()
class TPSGAME_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	ACharacterHUD* HUD;

	UPROPERTY(VisibleAnywhere, Category = "Character | Interaction")
	TScriptInterface<IInteractInterface> TargetInteractable;

	float InteractionCheckFrequency;

	float InteractionCheckDistance;

	FTimerHandle TimerHandle_Interaction;

	FInteractionData InteractionData;

	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<AActor> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<AActor> DashProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<AActor> BlackholeProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Attack")
	UAnimMontage* AttackAnim;

	FTimerHandle TimerHandle_PrimaryAttack;

	FTimerHandle TimerHandle_Dash;

	FTimerHandle TimerHandle_Blackhole;

	float AttackAnimDelay;

	UPROPERTY(VisibleAnywhere, Category = "Effects")
	FName TimeToHitParamName;

	UPROPERTY(VisibleAnywhere, Category = "Effects")
	FName HandSocketName;

	void SpawnProjectile(TSubclassOf<AActor> ClassToSpawn);

	UFUNCTION()
	void OnHealthChanged(AActor* InstigatorActor, USAttributeComponent* OwningComp, float NewHealth, float Delta);

	virtual void PostInitializeComponents() override;

	void Move(const FInputActionInstance& Instance);

	void Look(const FInputActionValue& Value);

	void PrimaryAttack();

	void PrimaryAttack_TimeElapsed();

	void Jump();

	void PrimaryInteract();

	void Teleport();

	void Teleport_TimeElapsed();

	void Blackhole_Attack();

	void Blackhole_TimeElapsed();

	void StartAttackEffects();

	void OpenInventory();

	void PerformInteractionCheck();

	void FoundInteractable(AActor* NewInteractable);

	void NoInteractableFound();

	void BeginInteract();

	void EndInteract();

	void Interact();



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE bool IsInteracting() const { return GetWorldTimerManager().IsTimerActive(TimerHandle_Interaction); };

	FORCEINLINE UInventoryComponent* GetInventory() const { return PlayerInventory; };

	void UpdateInteractionWidget() const;

protected:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp{ nullptr };

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp{ nullptr };

	UPROPERTY(VisibleAnywhere)
	USInteractionComponent* InteractComp;

	UPROPERTY(VisibleAnywhere, Category = "Inventory")
	UInventoryComponent* PlayerInventory;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USAttributeComponent* AttributeComp;

	UPROPERTY(EditAnywhere, Category = "Attacks")
	UParticleSystem* CastingEffect;

	UPROPERTY(EditAnywhere, Category = "Input", meta= (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext{ nullptr };

	UPROPERTY(EditAnywhere, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction{ nullptr };

	UPROPERTY(EditAnywhere, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction{ nullptr };

	UPROPERTY(EditAnywhere, Category = "Attacks", meta = (AllowPrivateAccess = "true"))
	UInputAction* PrimAttack{ nullptr };

	UPROPERTY(EditAnywhere, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction{ nullptr };

	UPROPERTY(EditAnywhere, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* InteractAction{ nullptr };
	
	UPROPERTY(EditAnywhere, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* TeleAction{ nullptr };

	UPROPERTY(EditAnywhere, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* HoleAction{ nullptr };

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* ViewInventory{ nullptr };

};
