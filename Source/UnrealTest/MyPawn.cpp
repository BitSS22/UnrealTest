// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "MyStruct.h"
#include "MyBackCube.h"
#include "EnhancedInputComponent.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
	for (int32 y = 0; y < SizeData.Y; ++y)
	{
		for (int32 x = 0; x < SizeData.X; ++x)
		{
			AActor* NewActor = GetWorld()->SpawnActor(AMyBackCube::StaticClass());
			NewActor->SetActorLocation(FVector(0.f, x * 100.f, y * 100.f));
		}
	}

	SetActorLocation(GetStartLocation());
	SetActorRotation(FQuat::Identity);
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);

	Input->
	PlayerInputComponent
}

