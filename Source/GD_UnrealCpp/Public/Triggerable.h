// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTrigger.h"
#include "Triggerable.generated.h"

UCLASS()
class GD_UNREALCPP_API ATriggerable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATriggerable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent)
	void OnTrigger(AActor* TouchedActor);

	UFUNCTION(BlueprintImplementableEvent)
	void OffTrigger();
	
	UPROPERTY(EditAnywhere) 
	AMyTrigger* Trigger;

};
