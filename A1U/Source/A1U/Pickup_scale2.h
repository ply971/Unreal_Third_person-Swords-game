// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Pickup_base.h"
#include "Pickup_scale2.generated.h"

UCLASS()
class APickup_scale2 : public APickup_base
{
    GENERATED_BODY()

public:
    APickup_scale2();

    virtual void Tick(float Delta) override;

protected:
    virtual void OnOverlap(
        UPrimitiveComponent* OverlappedComp,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 BodyIndex,
        bool bFromSweep,
        const FHitResult& Sweep) override;

    // bobbing settings
    UPROPERTY(EditAnywhere, Category = "Float")
    float FloatAmplitude = 20.f;
    UPROPERTY(EditAnywhere, Category = "Float")
    float FloatSpeed = 2.f;

    // how much to scale player by
    UPROPERTY(EditAnywhere, Category = "Effects")
    float ScaleFactor = 1.2f;

private:
    float RunningTime = 0.f;
};