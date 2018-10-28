// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyTrigger.h"
#include "MyInteractTrigger.generated.h"


class UBoxComponent;
class UStaticMeshComponent;



UCLASS()
class GD_UNREALCPP_API AMyInteractTrigger : public AMyTrigger
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyInteractTrigger();

protected:
	// Called when the game starts or when spawned 
	virtual void BeginPlay() override;


	///Creating pointers to components
	UPROPERTY(EditDefaultsOnly)
	USceneComponent* SceneComp;

	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* TriggerVolume;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* MyMesh;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
