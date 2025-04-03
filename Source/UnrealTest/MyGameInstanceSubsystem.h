// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MyGameInstanceSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class UNREALTEST_API UMyGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FIntPoint Size = {10, 20};

	void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable)
	void SetSize(FIntPoint _Size)
	{
		Size = _Size;
	}

	UFUNCTION(BlueprintCallable)
	FIntPoint GetSize()
	{
		return Size;
	}

	UFUNCTION(BlueprintCallable)
	FVector GetStartLocation()
	{
		return FVector(-100.f, Size.X * 50.f, Size.Y * 100.f);
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDataTable* Asset = nullptr;
};
