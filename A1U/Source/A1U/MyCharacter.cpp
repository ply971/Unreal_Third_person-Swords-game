#include "MyCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EngineUtils.h"

AMyCharacter::AMyCharacter()
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
}


void AMyCharacter::BeginPlay()
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

void AMyCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value * GetWorld()->GetDeltaSeconds() * SpeedMultiplier);
}

void AMyCharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value * GetWorld()->GetDeltaSeconds() * SpeedMultiplier);
}

void AMyCharacter::LookHorizontaly(float Value)
{
	AddControllerYawInput(Value);
}

void AMyCharacter::LookVertically(float Value)
{
	AddControllerPitchInput(-Value);
}

void AMyCharacter::ChangeCamera()
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

void AMyCharacter::StartSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
}

void AMyCharacter::StopSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;
}

void AMyCharacter::StartSlowmo()
{
	GetCharacterMovement()->MaxWalkSpeed = SlowSpeed;
}

void AMyCharacter::StopSlowmo()
{
	GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;
}

void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("W_KEY", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("D_KEY", this, &AMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis("S_KEY", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("A_KEY", this, &AMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MOUSE_X", this, &AMyCharacter::LookHorizontaly);
	PlayerInputComponent->BindAxis("MOUSE_Y", this, &AMyCharacter::LookVertically);

	PlayerInputComponent->BindAction("Change_Camera", IE_Pressed, this, &AMyCharacter::ChangeCamera);

	PlayerInputComponent->BindAction("SHIFT_KEY", IE_Pressed, this, &AMyCharacter::StartSprint);
	PlayerInputComponent->BindAction("SHIFT_KEY", IE_Released, this, &AMyCharacter::StopSprint);
	PlayerInputComponent->BindAction("CTRL_KEY", IE_Pressed, this, &AMyCharacter::StartSlowmo);
	PlayerInputComponent->BindAction("CTRL_KEY", IE_Released, this, &AMyCharacter::StopSlowmo);
}

