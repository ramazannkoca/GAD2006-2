// Fill out your copyright notice in the Description page of Project Settings.


#include "CAOPlayer1.h"

ACAOPlayer1::ACAOPlayer1() :


	//Stamina
	CurrentStamina (100),
	MaxStamina(100),
	MinStamina(0),
	StaminaGainRate(2),
	StaminaDrainRate(1),
	StaminaGainDelay(100),
	bStaminaDrained(false),
	bRunning(false),
	RunSpeed(600.0f)
{

	mSprinArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	mSprinArm->TargetArmLength = 300.0f;
	mSprinArm->SetupAttachment(RootComponent);

	mCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	mCamera->SetupAttachment(mSprinArm, USpringArmComponent::SocketName);

	mCamera->bUsePawnControlRotation = false;
	mSprinArm->bUsePawnControlRotation = true;
	bUseControllerRotationYaw = false;

}
void ACAOPlayer1::BeginPlay()
{
	Super::BeginPlay();

	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;

}
void ACAOPlayer1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateMovementParams();

}

void ACAOPlayer1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Turn", this, &ACharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &ACharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("MoveForward", this, &ACAOPlayer1::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACAOPlayer1::MoveRight);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &ACAOPlayer1::RunPressed);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &ACAOPlayer1::RunReleased);





}

void ACAOPlayer1::MoveForward(float value)
{
	FRotator Rotation = GetController()->GetControlRotation();
	FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
	FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(ForwardDirection, value);
}

void ACAOPlayer1::MoveRight(float value)
{
	FRotator Rotation = GetController()->GetControlRotation();
	FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
	FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(RightDirection, value);
}

void ACAOPlayer1::RunPressed()
{

	FVector Velocity = GetVelocity();
	float speed = Velocity.Size();
	if (speed > 0.0f)
	{
		bRunning = true;
		if (bStaminaDrained == false)
		{
			GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
		}
	}
	
	

}

void ACAOPlayer1::RunReleased()
{
	bRunning = false;
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;

}



void ACAOPlayer1::UpdateMovementParams()
{
	if (bRunning == true && bStaminaDrained == false)
	{
		FMath::Min(MinStamina, CurrentStamina -= StaminaDrainRate);

		if (CurrentStamina <= 0)
		{
			RunReleased();
			bStaminaDrained = true;
			StaminaGainDelay = 100;
		}
	}
	else if (!bRunning && !bStaminaDrained)
	{
		if (CurrentStamina < MaxStamina)
		{
			FMath::Min(MaxStamina, CurrentStamina += StaminaDrainRate);
		}
	}
	
	else if (bStaminaDrained)
	{
		FMath::Max	(0, StaminaGainDelay--);
		if (StaminaGainDelay <= 0)
		{
			FMath::Min(MaxStamina, CurrentStamina += StaminaGainRate);
			bStaminaDrained = false;
		}
	}
	
	

}




