// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup_speed.h"
#include "MyCharacter2.h"


APickup_speed::APickup_speed()
{
    PrimaryActorTick.bCanEverTick = true;
}

void APickup_speed::Tick(float Delta)
{
    Super::Tick(Delta);

  
    AddActorLocalRotation(FRotator(0.f, RotationSpeed * Delta, 0.f));
}

void APickup_speed::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 BodyIndex,
    bool bFromSweep, const FHitResult& Sweep)
{
    if (auto* Player = Cast<AMyCharacter2>(OtherActor))
    {
       
        Player->SprintSpeed *= 1.5;
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue,
                FString::Printf(TEXT("Speed Boost! New Speed: %.0f"), Player->SprintSpeed));
        }
        Destroy();
    }
}
