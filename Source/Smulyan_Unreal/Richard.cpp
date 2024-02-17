// Fill out your copyright notice in the Description page of Project Settings.


#include "Richard.h"

#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ARichard::ARichard()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment (RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(CameraBoom);

}

// Called when the game starts or when spawned
void ARichard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARichard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARichard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Move_X", this, &ARichard::Move_X);
	PlayerInputComponent->BindAxis("Move_Y", this, &ARichard::Move_Y);
	PlayerInputComponent->BindAxis("Look_X", this, &ARichard::Look_X);
	PlayerInputComponent->BindAxis("Look_Y", this, &ARichard::Look_Y);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ARichard::Jump);
}

void ARichard::Print(FString mes)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, mes);
}

void ARichard::Move_X(float value)
{
	if(value > 0.0f || value < 0.0f)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(RightDirection, value);
	}
}

void ARichard::Move_Y(float value)
{
	if(value > 0.0f || value < 0.0f)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		AddMovementInput(ForwardDirection, value);
		
	}
}

void ARichard::Look_X(float value)
{
	AddControllerYawInput(value);
}

void ARichard::Look_Y(float value)
{
	//uninvert camera
	AddControllerPitchInput(-value);
}

