#include "InteractableMesh.h"

#include "Kismet/GameplayStatics.h"

AInteractableMesh::AInteractableMesh()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;
}

void AInteractableMesh::BeginPlay()
{
	Super::BeginPlay();
	if (MeshA) { MeshComponent->SetStaticMesh(MeshA); }

}


void AInteractableMesh::ChangeMesh()
{
	if (bUsingMeshA && MeshB) {
		MeshComponent->SetStaticMesh(MeshB);
		bUsingMeshA = false;
	}
	else if (!bUsingMeshA && MeshA) {
		MeshComponent->SetStaticMesh(MeshA);
		bUsingMeshA = true;
	}
}


