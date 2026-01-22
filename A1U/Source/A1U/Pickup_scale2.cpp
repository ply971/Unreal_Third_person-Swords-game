// Fill out your copyright notice in the Description page of Project Settings.



#include "Pickup_scale2.h"
#include "MyCharacter2.h"

APickup_scale2::APickup_scale2()
{
    PrimaryActorTick.bCanEverTick = true;
}

void APickup_scale2::Tick(float Delta)
{
    Super::Tick(Delta);

    RunningTime += Delta * FloatSpeed;
    
    FVector Loc = GetActorLocation();
    Loc.Z += FMath::Sin(RunningTime) * FloatAmplitude * Delta;
    SetActorLocation(Loc);
}

void APickup_scale2::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 BodyIndex,
    bool bFromSweep, const FHitResult& Sweep)
{
    if (auto* Player = Cast<AMyCharacter2>(OtherActor))
    {
        // scale player
        FVector NewScale = Player->GetActorScale3D() * ScaleFactor;
        Player->SetActorScale3D(NewScale);

        Destroy();
    }
}