#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableMesh.generated.h"

UCLASS()
class AInteractableMesh : public AActor
{
	GENERATED_BODY()

public:
	AInteractableMesh();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, Category = "Meshes")
	UStaticMesh* MeshA;

	UPROPERTY(EditAnywhere, Category = "Meshes")
	UStaticMesh* MeshB;

	bool bUsingMeshA = true;

	void ChangeMesh();
};