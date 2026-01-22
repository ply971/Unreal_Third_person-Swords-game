// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class AMyCharacter: public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    AMyCharacter();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame


    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    //Camera boom positioning the camera behind the Character /
        UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    class USpringArmComponent* CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    class UCameraComponent* ThirdPersonCamera;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    class UCameraComponent* FirstPersonCamera;


  
        void MoveForward(float Value);
    void MoveRight(float Value);
    void LookHorizontaly(float Value);
    void LookVertically(float Value);
    void ChangeCamera();


     
    void StartSprint();
    void StopSprint();
    void StartSlowmo();
    void StopSlowmo();

    

   
     UPROPERTY(EditAnywhere, Category = "Movement")
    float NormalSpeed = 500.f;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float SprintSpeed = 1000.f;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float SlowSpeed = 100.f;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float SpeedMultiplier = 1000.f;


    bool IsFirstPerson = false;
};
