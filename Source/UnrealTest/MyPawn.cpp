// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "MyStruct.h"
#include "MyBackCube.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "MyPlayerController.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*AMyPlayerController* PlayerController = Cast<AMyPlayerController>(GetController());
	if (PlayerController != nullptr)
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
			PlayerController->GetLocalPlayer());
		if (Subsystem != nullptr)
		{
			Subsystem->AddMappingContext(MappingContext, 0);
		}
	}*/

	static ConstructorHelpers::FObjectFinder<UInputMappingContext> Path(TEXT("/Script/EnhancedInput.InputMappingContext'/Game/IMC_MyInputMappingComtext.IMC_MyInputMappingComtext'"));
	if (Path.Succeeded())
		MappingContext = Path.Object;
	
	static ConstructorHelpers::FObjectFinder<UInputAction> MovePath(TEXT("/Script/EnhancedInput.InputAction'/Game/IA_Move.IA_Move'"));
	if (MovePath.Succeeded())
		MoveInput = MovePath.Object;

	static ConstructorHelpers::FObjectFinder<UInputAction> RotatePath(TEXT("/Script/EnhancedInput.InputAction'/Game/IA_Rotate.IA_Rotate'"));
	if (RotatePath.Succeeded())
		RotateInput = RotatePath.Object;
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* SubSystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			SubSystem->AddMappingContext(MappingContext, 0);
	}

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
	
	Input->BindAction(MoveInput, ETriggerEvent::Triggered, this, &AMyPawn::Move);
	Input->BindAction(RotateInput, ETriggerEvent::Triggered, this, &AMyPawn::Rotate);
}

void AMyPawn::Move(const FInputActionValue& Value)
{
	FVector2D Vector = Value.Get<FVector2D>();
	AddActorWorldOffset({ 0.f ,Vector.X * 100.f, Vector.Y * 100.f });
}

void AMyPawn::Rotate(const FInputActionValue& Value)
{
	int a = 0;
}

