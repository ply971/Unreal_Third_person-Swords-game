// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup_base.h"
#include "Components/BoxComponent.h"

// Sets default values
APickup_base::APickup_base()
{
    PrimaryActorTick.bCanEverTick = true;

    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
    SetRootComponent(MeshComp);

    BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
    BoxComp->SetupAttachment(MeshComp);
    BoxComp->SetCollisionProfileName("OverlapAll");
}

void APickup_base::BeginPlay()
{
    Super::BeginPlay();

    BoxComp->OnComponentBeginOverlap.AddDynamic(this, &APickup_base::OnOverlap);
    SetLifeSpan(LifeSpanSeconds);
}

void APickup_base::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 BodyIndex,
    bool bFromSweep, const FHitResult& Sweep)
{
}

