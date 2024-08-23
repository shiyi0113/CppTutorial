#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "MoveComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPPTUTORIAL_API UMoveComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	UMoveComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
protected:
	virtual void BeginPlay() override;
private:
	FVector StartRelativeLocation;
	UPROPERTY(EditAnywhere);
	FVector MoveOffset;
	UPROPERTY(EditAnywhere);
	float speed = 100.0f;            //移动速度
	float MaxDistance = 0.0f;      //最大移动距离
	float CurDistance = 0.0f;      //当前移动距离
	FVector MoveOffsetNorm;
	int MoveDirection = 1;
};
