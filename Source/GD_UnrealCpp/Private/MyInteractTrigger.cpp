// Fill out your copyright notice in the Description page of Project Settings.

#include "MyInteractTrigger.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AMyInteractTrigger::AMyInteractTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	///Instantiating our components, also setting collisions
	SceneComp = CreateDefaultSubobject<USceneComponent>("ActorRoot");
	RootComponent = SceneComp;

	TriggerVolume = CreateDefaultSubobject<UBoxComponent>("TriggerVolume");
	TriggerVolume->SetBoxExtent(FVector(100.f));
	TriggerVolume->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	TriggerVolume->SetupAttachment(SceneComp);									///Basically parenting to SceneComponent

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	MyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MyMesh->SetupAttachment(SceneComp);

}

// Called when the game starts or when spawned 
void AMyInteractTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyInteractTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

