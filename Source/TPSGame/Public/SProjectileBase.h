// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SProjectileBase.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UParticleSystemComponent;
class UAudioComponent;
class USoundBase;
class UCameraShakeBase;

UCLASS(Abstract) // ABSTRACT marks this class as incomplete, keeping this out of certain dropdown windows like SpawnActor in UE
class TPSGAME_API ASProjectileBase : public AActor
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Effects")
	UParticleSystem* ImpactVFX;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* SphereComp;

	UPROPERTY(EditDefaultsOnly, Category = "Audio")
	UAudioComponent* AudioComp;

	UPROPERTY(EditDefaultsOnly, Category = "Audio")
	USoundBase* ImpactSound;

	UPROPERTY(EditDefaultsOnly, Category = "Shake")
	TSubclassOf<UCameraShakeBase> ImpactShake;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UProjectileMovementComponent* MoveComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UParticleSystemComponent* EffectComp;

	// virtual so we can override this in child-classes

	UFUNCTION()
	virtual void OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	// BlueprintNativeEvent = C++ Implementation, can be expanded in Blueprints
	// BlueprintCallable to allow child classes to trigger explosions

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Explode();

	virtual void PostInitializeComponents() override;

	float ImpactShakeInnerRadius;

	float ImpactShakeOuterRadius;


public:	
	// Sets default values for this actor's properties
	ASProjectileBase();
};
