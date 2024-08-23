#include "TimeManager.h"

ATimeManager::ATimeManager()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ATimeManager::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (TimeReversalAbilityEnabled) {
		CurrentRecordedTime = TMathUtil<float>::Min(ReverseTimeMaximum, CurrentRecordedTime + DeltaSeconds * CurrentTimeFactor);
		if (CurrentRecordedTime <= 0.0f) {
			EndTimeReverse();
			CurrentRecordedTime = 0.0f;
		}
	}
}


void ATimeManager::BeginPlay()
{
	Super::BeginPlay();
	CurrentTimeFactor = NormalTimeFactor;
}

float ATimeManager::GetTimeFactor()
{
	return CurrentTimeFactor;
}

void ATimeManager::BeginTimeReverse()
{
	if(GetAbilityAvailible())
		CurrentTimeFactor = ReverseTimeFactor;
}

void ATimeManager::EndTimeReverse()
{
	CurrentTimeFactor = NormalTimeFactor;
}

void ATimeManager::EnableTimeReverseAbility()
{
	if (!TimeReversalAbilityEnabled)
		TimeReversalAbilityEnabled = true;
}

void ATimeManager::DisableTimeReverseAbility()
{
	if (TimeReversalAbilityEnabled) {
		EndTimeReverse();
		CurrentRecordedTime = 0.0f;
		TimeReversalAbilityEnabled = false;
	}
}

bool ATimeManager::GetAbilityAvailible()
{
	return TimeReversalAbilityEnabled && CurrentRecordedTime >= ReverseTimeThreshhold;
}

float ATimeManager::GetCurrentReversableTime()
{
	return CurrentRecordedTime;
}
