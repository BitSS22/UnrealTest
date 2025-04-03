// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyStruct.h"
#include "InputMappingContext.h"
#include "MyPawn.generated.h"

UCLASS()
class UNREALTEST_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSize SizeData = {};

	UFUNCTION(BlueprintCallable)
	FVector GetStartLocation()
	{
		return FVector(-100.f, SizeData.X * 50.f, SizeData.Y * 100.f);
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInputMappingContext* MappingContext = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInputAction* MoveInput = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInputAction* RotateInput = nullptr;

	UFUNCTION(BlueprintCallable)
	void Move(const FInputActionValue& Value);

	UFUNCTION(BlueprintCallable)
	void Rotate(const FInputActionValue& Value);
};
