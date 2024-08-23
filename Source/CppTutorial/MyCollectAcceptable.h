#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MyCollectAcceptable.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UMyCollectAcceptable : public UInterface
{
	GENERATED_BODY()
};

class CPPTUTORIAL_API IMyCollectAcceptable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void Collect(UObject* SourceObj, float Count);

};
