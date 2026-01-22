// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChangingMaterial.generated.h"

UCLASS()
class AChangingMaterial : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AChangingMaterial();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Rotation")
	float RotationSpeed = 360.0f;

	UPROPERTY(EditAnywhere, Category = "Material")
	UMaterialInterface* Material1;

	UPROPERTY(EditAnywhere, Category = "Material")
	UMaterialInterface* Material2;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	int RotationAngle = 0;
	int TotalRotations = 0;
};