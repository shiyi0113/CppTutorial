#include "XPPawn.h"

AXPPawn::AXPPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	RootComponent = PlayerMesh;
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(PlayerMesh);

}

void AXPPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void AXPPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AXPPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveFB"), this, &AXPPawn::MoveFB);
	PlayerInputComponent->BindAxis(TEXT("MoveLR"), this, &AXPPawn::MoveLR);
	PlayerInputComponent->BindAxis(TEXT("Rotate"), this, &AXPPawn::Rotate);
}

void AXPPawn::MoveFB(float Value)
{
	auto Location = GetActorLocation();
	Location += GetActorForwardVector() * Value * MoveSpeed;
	SetActorLocation(Location);

}

void AXPPawn::MoveLR(float Value)
{
	auto Location = GetActorLocation();
	Location += GetActorRightVector() * Value * MoveSpeed;
	SetActorLocation(Location);

}

void AXPPawn::Rotate(float Value)
{
	auto Rotation = GetActorRotation();
	Rotation.Yaw += Value * RotationSpeed;
	SetActorRotation(Rotation);
}
