// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup_base.h"
#include "Pickup_health.generated.h"

UCLASS()
class A1U_API APickup_health : public APickup_base
{
    GENERATED_BODY()

public:
    APickup_health();

    virtual void Tick(float DeltaTime) override;

protected:
    virtual void OnOverlap(
        UPrimitiveComponent* OverlappedComp,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 BodyIndex,
        bool bFromSweep,
        const FHitResult& Sweep) override;

    UPROPERTY(EditAnywhere, Category = "Effects")
    float HealAmount = 25.f;

    UPROPERTY(EditAnywhere, Category = "Rotation")
    float RotationSpeed = 90.f;
};
