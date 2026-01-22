// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickup_base.generated.h"

UCLASS()
class A1U_API APickup_base : public AActor
{
    GENERATED_BODY()

public:
    APickup_base();

protected:
    // Called at start
    virtual void BeginPlay() override;

    // Called on overlap
    UFUNCTION()
    virtual void OnOverlap(
        UPrimitiveComponent* OverlappedComp,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 OtherBodyIndex,
        bool bFromSweep,
        const FHitResult& SweepResult);

    // Auto-destroy if not picked up
    UPROPERTY(EditAnywhere, Category = "Pickup|Lifetime")
    float LifeSpanSeconds = 10.f;

    // Mesh & collision
    UPROPERTY(VisibleAnywhere)
    class UStaticMeshComponent* MeshComp;
    UPROPERTY(VisibleAnywhere)
    class UBoxComponent* BoxComp;
};
