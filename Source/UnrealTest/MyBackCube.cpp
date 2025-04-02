// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBackCube.h"

// Sets default values
AMyBackCube::AMyBackCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	MeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ConstructorHelpers::FObjectFinder<UStaticMesh> Path(L"/Script/Engine.StaticMesh'/Engine/BasicShapes/Cube.Cube'");
	if (Path.Succeeded())
		MeshComponent->SetStaticMesh(Path.Object);

}

// Called when the game starts or when spawned
void AMyBackCube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyBackCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

