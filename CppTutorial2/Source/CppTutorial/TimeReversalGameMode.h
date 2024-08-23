#pragma once

#include "TimeManager.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TimeReversalGameMode.generated.h"

UCLASS()
class CPPTUTORIAL_API ATimeReversalGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	ATimeManager* GetTimeManager();

	void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
protected:
	UPROPERTY(BlueprintReadOnly)
	ATimeManager* TimeManager = nullptr;
};
