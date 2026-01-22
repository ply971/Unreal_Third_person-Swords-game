// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup_health.h"
#include "MyCharacter2.h"

APickup_health::APickup_health()
{
    PrimaryActorTick.bCanEverTick = true;
}

void APickup_health::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    //AddActorLocalRotation(FRotator(0.f, RotationSpeed * DeltaTime, 0.f));
}

void APickup_health::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 BodyIndex,
    bool bFromSweep, const FHitResult& Sweep)
{
    if (AMyCharacter2* Player = Cast<AMyCharacter2>(OtherActor))
    {
        if (Player->GetHealth() < Player->MaxHealth)
        {
            float NewHealth = Player->GetHealth() + HealAmount;
            Player->SetHealth(NewHealth);

            UE_LOG(LogTemp, Log, TEXT("Player healed. New Health: %f"), Player->GetHealth());
        }

        Destroy();
    }
}
