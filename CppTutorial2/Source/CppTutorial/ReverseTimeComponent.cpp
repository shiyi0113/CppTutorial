#include "ReverseTimeComponent.h"


UReverseTimeComponent::UReverseTimeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UReverseTimeComponent::BeginPlay()
{
	Super::BeginPlay();
	ATimeReversalGameMode* GameMode = Cast<ATimeReversalGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode) {
		TimeManager = GameMode->GetTimeManager();
	}
	if (!TimeManager) {
		UE_LOG(LogTemp, Error, TEXT("Actor \"%s\" failed to receive global time manager!"),*GetName())
	}
}


