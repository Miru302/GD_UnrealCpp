// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTrigger.h"



// Sets default values
AMyTrigger::AMyTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void AMyTrigger::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);
	
}

