// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyBackCube.h"
#include "MyGameInstanceSubsystem.h"

void AMyGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	UMyGameInstanceSubsystem* Subsystem = GetGameInstance()->GetSubsystem<UMyGameInstanceSubsystem>();

	for (int32 y = 0; y < Subsystem->GetSize().Y; ++y)
	{
		for (int32 x = 0; x < Subsystem->GetSize().X; ++x)
		{
			AActor* NewActor = GetWorld()->SpawnActor(AMyBackCube::StaticClass());
			NewActor->SetActorLocation(FVector(0.f, x * 100.f, y * 100.f));
		}
	}
	
}
