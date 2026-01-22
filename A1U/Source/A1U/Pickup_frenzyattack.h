// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup_base.h"
#include "Pickup_frenzyattack.generated.h"

UCLASS()
class A1U_API APickup_frenzyattack : public APickup_base
{
    GENERATED_BODY()
public:
    APickup_frenzyattack();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    virtual void OnOverlap(
        UPrimitiveComponent* OverlappedComp,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 BodyIndex,
        bool bFromSweep,
        const FHitResult& Sweep) override;
};