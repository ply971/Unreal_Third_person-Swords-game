// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingLight.h"

#include "Components/PointLightComponent.h"
#include"Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"


ARotatingLight::ARotatingLight()
{
PrimaryActorTick.bCanEverTick = true;
CourseActorMesh= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CourseActorMesh"));
SetRootComponent(CourseActorMesh);

LightComponent = CreateDefaultSubobject<UPointLightComponent>(TEXT("LightComponent"));
LightComponent->SetupAttachment(RootComponent);
LightComponent->SetVisibility(false);
}

void ARotatingLight::BeginPlay()
{
Super::BeginPlay();

PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

}

void ARotatingLight::Tick(float DeltaTime)
{
Super::Tick(DeltaTime);

if (PlayerPawn)
{
float Distance = FVector::Dist(GetActorLocation(), PlayerPawn->GetActorLocation());

if (Distance <= ActivationDistance)
{
LightComponent->SetVisibility(true);
}
else
{
LightComponent->SetVisibility(false);
}
FRotator Rotation = GetActorRotation();
Rotation.Yaw += 45.f * DeltaTime; 
SetActorRotation(Rotation);
}
}

//void ARotatingLight::CheckLifetime()
//{
//ActorLevel= ActorLifetime; //will convert float to int32 implicitly}
//}

// Called to bind functionality to input




