#include "XPCharacter.h"

AXPCharacter::AXPCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	PlayerMesh->SetupAttachment(GetCapsuleComponent());
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(GetCapsuleComponent());

}

void AXPCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AXPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AXPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveFB"), this, &AXPCharacter::MoveFB);
	PlayerInputComponent->BindAxis(TEXT("MoveLR"), this, &AXPCharacter::MoveLR);
	PlayerInputComponent->BindAxis(TEXT("Rotate"), this, &AXPCharacter::Rotate);

}

void AXPCharacter::MoveFB(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value * MoveSpeed);
}

void AXPCharacter::MoveLR(float Value)
{
	AddMovementInput(GetActorRightVector(), Value * MoveSpeed);
}

void AXPCharacter::Rotate(float Value)
{
	AddControllerYawInput(Value * RotationSpeed);
}