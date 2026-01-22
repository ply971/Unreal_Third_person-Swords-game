// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingLight.generated.h"

UCLASS()
class ARotatingLight : public AActor
{
	GENERATED_BODY()

public:
	ARotatingLight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh Component")
	class UStaticMeshComponent* CourseActorMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Light Component")
	class UPointLightComponent* LightComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Light Component")
	float ActivationDistance = 400.f;

	APawn* PlayerPawn;
};