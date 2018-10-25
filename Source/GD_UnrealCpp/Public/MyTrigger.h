// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTrigger.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class GD_UNREALCPP_API AMyTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTrigger();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	///Creating pointers to components
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* TriggerVolume;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* MyMesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
	
};
