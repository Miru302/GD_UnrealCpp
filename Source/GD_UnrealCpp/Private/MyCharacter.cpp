// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacter.h"				///this class header file
#include "DrawDebugHelpers.h"			///DrawDebugLine()
#include "Components/InputComponent.h"	///UInputComponent->BindAction()
#include "Engine/World.h"				///GetWorld()

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction(FName("Fire"), IE_Pressed, this, &AMyCharacter::Fire);			///Binding "Fire" input to a function Fire(). "Fire" input is declared in project settings
}

void AMyCharacter::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire pressed"));
	if (!GetWorld()) { return; };																	///Check if UWorld exists

	///Setting up parameters for LineTrace
	FVector StartLocation;
	FRotator StartRotation;
	GetWorld()->GetFirstPlayerController()->GetActorEyesViewPoint(StartLocation, StartRotation);	///This function takes parameters in by reference and changes value in them
	FVector EndLocation = StartLocation + StartRotation.Vector() * Reach;							///Calculating end location for LineTrace		
	FCollisionObjectQueryParams CollisionObjParams = { ECollisionChannel::ECC_PhysicsBody};			///Setting what type of objects LineTrace will Hit
	FCollisionQueryParams CollisionQueryParams = { FName("FireTrace"), false, this };				///Setting TraceTag = "FireTrace". Now in PIE console we can...
	FHitResult HitResult;																			///...use command TraceTag FireTrace to visualize LineTrace

	//DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, 50.f, 0, 10.f);		///Another way for visualizing our LineTrace, requires #include "DrawDebugHelpers.h"

	if (GetWorld()->LineTraceSingleByObjectType(HitResult, StartLocation, EndLocation, CollisionObjParams, CollisionQueryParams)) ///LineTrace returns bool and sets values in HitResult
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit! %s"), *HitResult.GetActor()->GetName());
	}

}

