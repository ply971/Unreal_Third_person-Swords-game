#pragma once

#include "CoreMinimal.h"

#include "Pickup_base.h"
#include "Pickup_speed.generated.h"


UCLASS()
class A1U_API APickup_speed : public APickup_base
{
    GENERATED_BODY()

public:
    APickup_speed();

    virtual void Tick(float Delta) override;

protected:
    virtual void OnOverlap(
        UPrimitiveComponent* OverlappedComp,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 BodyIndex,
        bool bFromSweep,
        const FHitResult& Sweep) override;

    // rotation speed (degrees/sec)
    UPROPERTY(EditAnywhere, Category = "Rotation")
    float RotationSpeed = 90.f;

    // amount to change jogging speed by
    UPROPERTY(EditAnywhere, Category = "Effects")
    float SpeedDelta = 200.f;
};