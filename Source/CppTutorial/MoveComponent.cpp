#include "MoveComponent.h"


UMoveComponent::UMoveComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	StartRelativeLocation = GetRelativeLocation();   //起点为当前位置
	MoveOffsetNorm = MoveOffset;
	MoveOffsetNorm.Normalize();
	MaxDistance = MoveOffset.Length();
	SetComponentTickEnabled(MoveEnable);
}

void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (MoveEnable) {
		CurDistance += DeltaTime * speed * MoveDirection;
		if (CurDistance >= MaxDistance || CurDistance <= 0.0f)
			MoveDirection *= -1;
	}
	OnEndpointReached.Broadcast(CurDistance >= MaxDistance);
	CurDistance = FMath::Clamp(CurDistance, 0.0f, MaxDistance);
	SetRelativeLocation(StartRelativeLocation + MoveOffsetNorm * CurDistance);
}

void UMoveComponent::EnableMovement(bool ShouldMove)
{
	MoveEnable = ShouldMove;
	SetComponentTickEnabled(MoveEnable);
}

void UMoveComponent::ResetMovement()
{
	CurDistance = 0.0f;
	SetRelativeLocation(StartRelativeLocation);
}

void UMoveComponent::SetMoveDirection(int Direction)
{
	MoveDirection = Direction >= 1 ? 1 : -1;
}
