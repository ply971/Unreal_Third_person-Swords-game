// Fill out your copyright notice in the Description page of Project Settings.



#include "Pickup_frenzyattack.h"

#include "MyCharacter2.h"

// Sets default values
APickup_frenzyattack::APickup_frenzyattack()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APickup_frenzyattack::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void APickup_frenzyattack::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void APickup_frenzyattack::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 BodyIndex,
    bool bFromSweep, const FHitResult& Sweep)
{
    if (auto* Player = Cast<AMyCharacter2>(OtherActor))
    {
        Player->AttackDamage += 30;
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green,
                FString::Printf(TEXT("Attack Damage: %.0f"), Player->AttackDamage));
        }
        Destroy();
    }
}
