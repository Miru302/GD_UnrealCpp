// Fill out your copyright notice in the Description page of Project Settings.

#include "MyOverlapTrigger.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"

AMyOverlapTrigger::AMyOverlapTrigger()
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

void AMyOverlapTrigger::BeginPlay()
{
	Super::BeginPlay();

	if (TriggerVolume)
	{
		DrawDebugBox(GetWorld(), this->GetActorLocation(), TriggerVolume->GetScaledBoxExtent(), FColor::Cyan, true, 100.f, 0, 2.f); ///making the volume visible
	}
}


// Called every frame
void AMyOverlapTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

///This function is called whenever this actor's collision starts overlapping another actor (according to collision settings)
void AMyOverlapTrigger::NotifyActorBeginOverlap(AActor * OtherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *OtherActor->GetName()) 
	OnTrigger.Broadcast(OtherActor);
	
}
