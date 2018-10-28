// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"


#include "MyCharacter.generated.h" /// this should be the last #include

class UPhysicsHandleComponent;

UCLASS()
class GD_UNREALCPP_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

	float Reach;
public:
	// Sets default values for this character's properties 
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPhysicsHandleComponent* MyHandle; ///Creating a pointer to a Handle component.


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Grab();
	FHitResult LineTrace();
	
	void Use();

};
