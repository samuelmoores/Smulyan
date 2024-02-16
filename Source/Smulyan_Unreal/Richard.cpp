// Fill out your copyright notice in the Description page of Project Settings.


#include "Richard.h"

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

	PlayerInputComponent->BindAxis("Forward", this, &ARichard::Move);

}

void ARichard::Print(FString mes)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, mes);
}

void ARichard::Move(float value)
{
	Print(FString::SanitizeFloat(value));
}

