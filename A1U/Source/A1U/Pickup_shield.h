// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "CoreMinimal.h"
#include "Pickup_base.h"
#include "GameFramework/Actor.h"
#include "Pickup_shield.generated.h"

UCLASS()
class APickup_shield : public APickup_base
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    APickup_shield();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
    virtual void OnOverlap(
        UPrimitiveComponent* OverlappedComp,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 BodyIndex,
        bool bFromSweep,
        const FHitResult& Sweep) override;

};