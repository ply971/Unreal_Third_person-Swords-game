// Fill out your copyright notice in the Description page of Project Settings.


#include "ChangingMaterial.h"

AChangingMaterial::AChangingMaterial()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

}

void AChangingMaterial::BeginPlay()
{
	Super::BeginPlay();
	Mesh->SetMaterial(0, Material1);
}

// Called every frame
void AChangingMaterial::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Rotate around Y-axis
	FRotator Rotation = GetActorRotation();
	Rotation.Yaw += RotationSpeed * DeltaTime;
	SetActorRotation(Rotation);

	RotationAngle += RotationSpeed * DeltaTime;
	if (RotationAngle >= 360.0f) {
		TotalRotations++;
		RotationAngle -= 360;

		if (TotalRotations == 10 && Mesh && Material1 && Material2)
		{
			
				if (Mesh->GetMaterial(0) == Material1) { Mesh->SetMaterial(0, Material2); }
				else { Mesh->SetMaterial(0, Material1); }

			TotalRotations = 0;
		}
	}

}
