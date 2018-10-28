// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyTrigger.h"
#include "MyOverlapTrigger.generated.h"


class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class GD_UNREALCPP_API AMyOverlapTrigger : public AMyTrigger
{
	GENERATED_BODY()
	
public:
	AMyOverlapTrigger();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	///Creating pointers to components
	UPROPERTY(EditDefaultsOnly)
	USceneComponent* SceneComp; 

	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* TriggerVolume;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* MyMesh;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;


	
};
