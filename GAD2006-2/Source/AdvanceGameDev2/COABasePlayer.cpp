// Fill out your copyright notice in the Description page of Project Settings.


#include "COABasePlayer.h"

// Sets default values
ACOABasePlayer::ACOABasePlayer() :

	bDead(false),
	Health(100.0f),
	MaxHealth(100.0f),
	HealingRate(0.0f),
	WalkSpeed(300.0f)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.f, 0.0f);

}

// Called when the game starts or when spawned
void ACOABasePlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACOABasePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACOABasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ACOABasePlayer::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (bDead) return 0.0f;
	DamageAmount = ModifyDamage(DamageAmount);
	Health -= DamageAmount;
	GEngine->AddOnScreenDebugMessage(1, 0, FColor::Cyan, FString::Printf(TEXT("Health: %f"), Health));
	if (Health <= 0)
	{
		bDead = true;
		APlayerController* PlayerController = Cast<APlayerController>(GetController());
		if (PlayerController) DisableInput(PlayerController);
	}
	return 0.0f;
}

