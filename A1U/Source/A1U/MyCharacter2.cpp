#include "MyCharacter2.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EngineUtils.h"
#include "InteractableMesh.h"	

AMyCharacter2::AMyCharacter2()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f;
	CameraBoom->bUsePawnControlRotation = true;

	ThirdPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdPersonCamera"));
	ThirdPersonCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	ThirdPersonCamera->bUsePawnControlRotation = false;

	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCamera->SetupAttachment(GetCapsuleComponent());
	FirstPersonCamera->bUsePawnControlRotation = true;

	GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
}


void AMyCharacter2::BeginPlay()
{
	Super::BeginPlay();
	if (GetMesh())
	{
		GetMesh()->SetVisibility(true);
		GetMesh()->SetHiddenInGame(false);
	}
	ThirdPersonCamera->SetVisibility(true);
	FirstPersonCamera->Activate();

	FirstPersonCamera->SetVisibility(false);
	FirstPersonCamera->Deactivate();

}

void AMyCharacter2::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		
		FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		
		if (Value < 0.0f) {
			Direction = -Direction; 
		}

		AddMovementInput(Direction, 1.0f); 

		
		FRotator NewRotation = Direction.Rotation();
		NewRotation.Pitch = 0;
		NewRotation.Roll = 0;

		FRotator CurrentRotation = GetActorRotation();
		FRotator InterpRotation = FMath::RInterpTo(CurrentRotation, NewRotation, GetWorld()->GetDeltaSeconds(), 10.0f); 

		SetActorRotation(InterpRotation);
	}
}

void AMyCharacter2::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		
		const FVector RightVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		
		FVector Direction = RightVector * Value;

		
		AddMovementInput(Direction, 1.0f); 

		
		FRotator NewRotation = Direction.Rotation();
		NewRotation.Pitch = 0;
		NewRotation.Roll = 0;

		FRotator CurrentRotation = GetActorRotation();
		FRotator InterpRotation = FMath::RInterpTo(CurrentRotation, NewRotation, GetWorld()->GetDeltaSeconds(), 10.0f); 

		SetActorRotation(InterpRotation);
	}
}
void AMyCharacter2::LookHorizontaly(float Value)
{
	AddControllerYawInput(Value);
}

void AMyCharacter2::LookVertically(float Value)
{
	AddControllerPitchInput(-Value);
}

void AMyCharacter2::ChangeCamera()
{
	IsFirstPerson = !IsFirstPerson;
	if (IsFirstPerson)
	{
		ThirdPersonCamera->SetVisibility(false);
		ThirdPersonCamera->Deactivate();

		FirstPersonCamera->SetVisibility(true);
		FirstPersonCamera->Activate();

	}
	else
	{
		ThirdPersonCamera->SetVisibility(true);
		ThirdPersonCamera->Activate();

		FirstPersonCamera->SetVisibility(false);
		FirstPersonCamera->Deactivate();

	}
}

void AMyCharacter2::StartSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
}

void AMyCharacter2::StopSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;
}

void AMyCharacter2::StartSlowmo()
{
	GetCharacterMovement()->MaxWalkSpeed = SlowSpeed;
}

void AMyCharacter2::StopSlowmo()
{
	GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;
}

void AMyCharacter2::Interact()
{
	FVector PlayerLocation = GetActorLocation();

	
	for (TActorIterator<AInteractableMesh> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AInteractableMesh* InteractableActor = *ActorItr;

		if (InteractableActor)
		{
			float Distance = FVector::Dist(PlayerLocation, InteractableActor->GetActorLocation());
			if (Distance <= 300.0f)
			{
				InteractableActor->ChangeMesh();
			}
		}
	}
}
void AMyCharacter2::SetHealth(float NewHealth)
{
	if (bIsProtected)
	{
		return;
	}
	// Clamp health within [0, MaxHealth]
	Health = FMath::Clamp(NewHealth, 0.f, MaxHealth);


	
}

float AMyCharacter2::GetHealth()
{
	return Health;
}
void AMyCharacter2::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter2::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter2::MoveRight);
	PlayerInputComponent->BindAxis("MoveBackward", this, &AMyCharacter2::MoveForward);
	PlayerInputComponent->BindAxis("MoveLeft", this, &AMyCharacter2::MoveRight);
	PlayerInputComponent->BindAxis("MOUSE_X", this, &AMyCharacter2::LookHorizontaly);
	PlayerInputComponent->BindAxis("MOUSE_Y", this, &AMyCharacter2::LookVertically);
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AMyCharacter2::Interact);

	PlayerInputComponent->BindAction("SwitchCamera", IE_Pressed, this, &AMyCharacter2::ChangeCamera);

	PlayerInputComponent->BindAction("IncreaseSpeed", IE_Pressed, this, &AMyCharacter2::StartSprint);
	PlayerInputComponent->BindAction("IncreaseSpeed", IE_Released, this, &AMyCharacter2::StopSprint);
	PlayerInputComponent->BindAction("DecreaseSpeed", IE_Pressed, this, &AMyCharacter2::StartSlowmo);
	PlayerInputComponent->BindAction("DecreaseSpeed", IE_Released, this, &AMyCharacter2::StopSlowmo);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter2::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyCharacter2::StopJumping);
	PlayerInputComponent->BindAction("TakeDamage", IE_Pressed, this, &AMyCharacter2::TakeDamageManual);

}
void AMyCharacter2::StartShield()
{
	bIsProtected = true;
	ShieldTimeRemaining = 30.0f;
	UE_LOG(LogTemp, Warning, TEXT("Shield activated: %f seconds remaining"), ShieldTimeRemaining);

	
	GetWorld()->GetTimerManager().SetTimer(
		ShieldTickTimerHandle,
		this,
		&AMyCharacter2::TickShield,
		1.0f,
		true
	);


	GetWorld()->GetTimerManager().SetTimer(
		ShieldTimerHandle,
		this,
		&AMyCharacter2::EndShield,
		30.0f,
		false
	);
}

void AMyCharacter2::TickShield()
{
	ShieldTimeRemaining -= 1.0f;
	if (ShieldTimeRemaining > 0.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("Shield time remaining: %f"), ShieldTimeRemaining);
	}
}

void AMyCharacter2::EndShield()
{
	bIsProtected = false;
	UE_LOG(LogTemp, Warning, TEXT("Shield ended"));

	
	GetWorld()->GetTimerManager().ClearTimer(ShieldTickTimerHandle);
	GetWorld()->GetTimerManager().ClearTimer(ShieldTimerHandle);
}
void AMyCharacter2::TakeDamageManual()
{
	if (bIsProtected)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan,
				FString::Printf(TEXT("Shield Active – %.0f seconds remaining"), ShieldTimeRemaining));
		}
		return;
	}


	SetHealth(Health - 10);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red,
			FString::Printf(TEXT("Player Took 10 Damage! Current Health: %.0f"), Health));
	}
}