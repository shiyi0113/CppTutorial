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

}

void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	CurDistance += DeltaTime * speed * MoveDirection;
	if (CurDistance >= MaxDistance || CurDistance <= 0.0f)
		MoveDirection *= -1;
	SetRelativeLocation(StartRelativeLocation + MoveOffsetNorm * CurDistance);

}

