// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup_scale.h"

// Sets default values
APickup_scale::APickup_scale()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APickup_scale::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickup_scale::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

