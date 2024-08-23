#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "MoveComponent.generated.h"

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveComponentReachEndPointSignature, bool, IsTopEndpoint);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPPTUTORIAL_API UMoveComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	UMoveComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
protected:
	virtual void BeginPlay() override;

private://变量
	FVector StartRelativeLocation; //起始位置
	UPROPERTY(EditAnywhere);
	FVector MoveOffset;            //偏移量
	UPROPERTY(EditAnywhere);
	float speed = 100.0f;          //移动速度
	float MaxDistance = 0.0f;      //最大移动距离
	float CurDistance = 0.0f;      //当前移动距离
	FVector MoveOffsetNorm;        //移动方向
	int MoveDirection = 1;         //前进后退控制
	bool MoveEnable = false;       //是否移动
	UPROPERTY(BlueprintAssignable)
	FOnMoveComponentReachEndPointSignature OnEndpointReached;

private://函数
	UFUNCTION(BlueprintCallable)
	void EnableMovement(bool ShouldMove); //是否移动函数
	UFUNCTION(BlueprintCallable)  
	void ResetMovement();                 //回到原位函数
	UFUNCTION(BlueprintCallable)
	void SetMoveDirection(int Direction);

};
