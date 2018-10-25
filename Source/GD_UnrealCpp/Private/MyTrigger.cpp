// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTrigger.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"


// Sets default values
AMyTrigger::AMyTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	///Instantiating our components, also setting collisions
	TriggerVolume = CreateDefaultSubobject<UBoxComponent>("TriggerVolume");
	TriggerVolume->SetBoxExtent(FVector(100.f));
	TriggerVolume->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	MyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MyMesh->AttachTo(TriggerVolume);

}

// Called when the game starts or when spawned
void AMyTrigger::BeginPlay()
{
	Super::BeginPlay();
	DrawDebugBox(GetWorld(), this->GetActorLocation(), TriggerVolume->GetScaledBoxExtent(), FColor::Cyan, true, 100.f, 0, 2.f); ///making the volume visible
}

///This function is called whenever this actor's collision starts overlapping another actor (according to collision settings)
void AMyTrigger::NotifyActorBeginOverlap(AActor * OtherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *OtherActor->GetName())
}

// Called every frame
void AMyTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

