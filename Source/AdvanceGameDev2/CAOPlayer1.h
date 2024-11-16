// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "COABasePlayer.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "CAOPlayer1.generated.h"

UCLASS()
class ADVANCEGAMEDEV2_API ACAOPlayer1 : public ACOABasePlayer
{
	GENERATED_BODY()

public:
	ACAOPlayer1();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	UCameraComponent* mCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	USpringArmComponent* mSprinArm;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;




	//Stamina Property
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stamina")
	float CurrentStamina;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stamina")
	float MaxStamina;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stamina")
	float MinStamina;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stamina")
	float StaminaGainRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stamina")
	float StaminaDrainRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stamina")
	float StaminaGainDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stamina")
	bool bStaminaDrained;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stamina")
	bool bRunning;

	UPROPERTY(EditAnywhere, Category = "Stamina")
	float RunSpeed;
	
	



private:
	//Movement Base
	void MoveForward(float value);
	void MoveRight(float value);
	void RunPressed();
	void RunReleased();

protected:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	//Stamina
	void UpdateMovementParams();

};
