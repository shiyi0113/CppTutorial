#pragma once

#include "TimeManager.h"
#include "TimeReversalGameMode.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ReverseTimeComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPPTUTORIAL_API UReverseTimeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UReverseTimeComponent();

protected:
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintReadOnly)
	ATimeManager* TimeManager = nullptr;
};
