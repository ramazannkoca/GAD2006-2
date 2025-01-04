// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "COABasePlayer.generated.h"

UCLASS()
class ADVANCEGAMEDEV2_API ACOABasePlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACOABasePlayer();

	UFUNCTION(BlueprintImplementableEvent)
	float ModifyDamage(float IncomingDamage);

	//COA Properties
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "COA")
	bool bDead;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "COA")
	float Health;
	UPROPERTY(EditAnywhere, Category = "COA")
	float MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "COA")
	float HealingRate;
	UPROPERTY(EditAnywhere, Category = "COA")
	float WalkSpeed;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//overriden
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;


};
