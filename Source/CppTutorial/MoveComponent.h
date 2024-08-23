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
	float speed = 100.0f;            //�ƶ��ٶ�
	float MaxDistance = 0.0f;      //����ƶ�����
	float CurDistance = 0.0f;      //��ǰ�ƶ�����
	FVector MoveOffsetNorm;
	int MoveDirection = 1;
};
