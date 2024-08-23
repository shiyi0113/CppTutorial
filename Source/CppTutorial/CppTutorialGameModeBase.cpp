#include "CppTutorialGameModeBase.h"

void ACppTutorialGameModeBase::InitGameState()
{
	Super::InitGameState();
	if (DefaultPawnClass == ADefaultPawn::StaticClass()) {
		DefaultPawnClass = CustomXPPawnClass;
	}
}
