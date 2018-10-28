// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTrigger.generated.h"

///Creating "EventDispatcher". OneParam can be changed to TwoParams, ThreeParams and so on. 
///Notice how type and name of parameter are separated by a ','
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActorTriggeredSignature, AActor*, TouchedActor);

UCLASS()
class GD_UNREALCPP_API AMyTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties 
	AMyTrigger();
protected:

	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
	FActorTriggeredSignature OnTrigger;

};
