#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine/StaticMesh.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "XPCharacter.generated.h"

UCLASS()
class CPPTUTORIAL_API AXPCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AXPCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* PlayerMesh;
	UPROPERTY(EditDefaultsOnly)
	UCameraComponent* PlayerCamera;
	UPROPERTY(EditAnywhere)
	float MoveSpeed = 1.0f;
	UPROPERTY(EditAnywhere)
	float RotationSpeed = 1.0f;
	void MoveFB(float Value);
	void MoveLR(float Value);
	void Rotate(float Value);

};
