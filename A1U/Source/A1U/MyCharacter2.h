// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter2.generated.h"
UCLASS()
class AMyCharacter2 : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    AMyCharacter2();

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
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float AttackDamage = 20.0f;



    void MoveForward(float Value);
    void MoveRight(float Value);
    void LookHorizontaly(float Value);
    void LookVertically(float Value);
    void ChangeCamera();



    void StartSprint();
    void StopSprint();
    void StartSlowmo();
    void StopSlowmo();
    void Interact();
    void StartShield();
    void TickShield();
    void EndShield();
 


    bool bIsProtected = false;
    float ShieldTimeRemaining = 0.f;

    FTimerHandle ShieldTimerHandle;
    FTimerHandle ShieldTickTimerHandle;


    UPROPERTY(EditAnywhere, Category = "Movement")
    float NormalSpeed = 500.f;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float SprintSpeed = 1000.f;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float SlowSpeed = 100.f;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float SpeedMultiplier = 1000.f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    float MaxHealth = 100.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    float Health = 100.f;

    UFUNCTION(BlueprintCallable, Category = "Health")
    void SetHealth(float NewHealth);
    float GetHealth();
    UFUNCTION()
    void TakeDamageManual();

    bool IsFirstPerson = false;
};
