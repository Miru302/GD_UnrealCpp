// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacter.h"							///this class header file, it should be the first #include
#include "DrawDebugHelpers.h"						///DrawDebugLine()
#include "Components/InputComponent.h"				///UInputComponent->BindAction()
#include "Engine/World.h"							///GetWorld()
#include "PhysicsEngine/PhysicsHandleComponent.h"	///For operations with MyHandle (UPhysicsHandleComponent)

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Reach = 1000.f;

	MyHandle = CreateDefaultSubobject<UPhysicsHandleComponent>("MyHandle"); ///Instantiating our PhysicsHandle component and assigning it to the pointer MyHandle

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

	if (MyHandle->GetGrabbedComponent())	///If we have something grabbed then we need to update it's location to keep it in front of us
	{
		FVector StartLocation;
		FRotator StartRotation;
		GetWorld()->GetFirstPlayerController()->GetActorEyesViewPoint(StartLocation, StartRotation);	///This function takes parameters in by reference and changes value in them
		FVector EndLocation = StartLocation + StartRotation.Vector() * 200.f;							/// 
		MyHandle->SetTargetLocation(EndLocation);
	}
	
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction(FName("Grab"), IE_Pressed, this, &AMyCharacter::Grab);			///Binding "Fire" input to a function Fire(). "Fire" input is declared in project settings
}

void AMyCharacter::Grab()
{
	UE_LOG(LogTemp, Warning, TEXT("Grab pressed"));
	if (!GetWorld()) { return; };							///SaveCheck if UWorld exists

	if (MyHandle->GetGrabbedComponent())					///If we already have a component grabbed, we release it instead
	{
		MyHandle->ReleaseComponent();
		return;
	}



	FHitResult HitResult = LineTrace();

	if (HitResult.GetActor())															///If HitResult have Actor then we proceed
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit! %s"), *HitResult.GetActor()->GetName());
		MyHandle->GrabComponent(
			HitResult.GetComponent(),
			NAME_None,
			HitResult.GetActor()->GetActorLocation(),									
			true																		///Constraining rotation of the grabbed component
		);
	}
	
}

FHitResult AMyCharacter::LineTrace()
{
	///Setting up parameters for LineTrace
	FVector StartLocation;
	FRotator StartRotation;
	GetWorld()->GetFirstPlayerController()->GetActorEyesViewPoint(StartLocation, StartRotation);	///This function takes parameters in by reference and changes value in them
	FVector EndLocation = StartLocation + StartRotation.Vector() * Reach;							///Calculating end location for LineTrace		
	FCollisionObjectQueryParams CollisionObjParams = { ECollisionChannel::ECC_PhysicsBody };		///Setting what type of objects LineTrace will Hit
	FCollisionQueryParams CollisionQueryParams = { FName("GrabTrace"), false, this };				///Setting TraceTag = "FireTrace". Now in PIE console we can...
	FHitResult HitResult;																			///...use command TraceTag FireTrace to visualize LineTrace

	
	///DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, 0.3f, 0, 1.f);			///Another way for visualizing our LineTrace, requires #include "DrawDebugHelpers.h"
	GetWorld()->LineTraceSingleByObjectType(HitResult, StartLocation, EndLocation, CollisionObjParams, CollisionQueryParams);  ///LineTrace
	return HitResult;
}

