// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_shield.h"

#include "MyCharacter2.h"

// Sets default values
APickup_shield::APickup_shield()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APickup_shield::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void APickup_shield::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void APickup_shield::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 BodyIndex,
    bool bFromSweep, const FHitResult& Sweep)
{
    if (auto* Player = Cast<AMyCharacter2>(OtherActor))
    {
        Player->StartShield();
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Cyan,
                TEXT("Invulnerability Shield Activated!"));
        }
        Destroy();
    }
}