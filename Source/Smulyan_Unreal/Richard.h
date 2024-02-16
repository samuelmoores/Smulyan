// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Richard.generated.h"

UCLASS()
class SMULYAN_UNREAL_API ARichard : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARichard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	USpringArmComponent* CameraBoom;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Print(FString mes);

	void Move(float value);

	void Look_X(float value);
	void Look_Y(float value);


};
