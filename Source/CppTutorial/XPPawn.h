#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Engine/StaticMesh.h"
#include "Camera/CameraComponent.h"
#include "XPPawn.generated.h"

UCLASS()
class CPPTUTORIAL_API AXPPawn : public APawn
{
	GENERATED_BODY()

public:
	AXPPawn();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	virtual void BeginPlay() override;

private://±äÁ¿
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* PlayerMesh;
	UPROPERTY(EditDefaultsOnly)
	UCameraComponent* PlayerCamera;
	UPROPERTY(EditAnywhere)
	float MoveSpeed = 10.0f;
	UPROPERTY(EditAnywhere)
	float RotationSpeed = 1.0f;
	

private://º¯Êý
	void MoveFB(float Value);
	void MoveLR(float Value);
	void Rotate(float Value);
	

};
