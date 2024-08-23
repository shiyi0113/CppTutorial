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

private://����
	FVector StartRelativeLocation; //��ʼλ��
	UPROPERTY(EditAnywhere);
	FVector MoveOffset;            //ƫ����
	UPROPERTY(EditAnywhere);
	float speed = 100.0f;          //�ƶ��ٶ�
	float MaxDistance = 0.0f;      //����ƶ�����
	float CurDistance = 0.0f;      //��ǰ�ƶ�����
	FVector MoveOffsetNorm;        //�ƶ�����
	int MoveDirection = 1;         //ǰ�����˿���
	bool MoveEnable = false;       //�Ƿ��ƶ�
	UPROPERTY(BlueprintAssignable)
	FOnMoveComponentReachEndPointSignature OnEndpointReached;

private://����
	UFUNCTION(BlueprintCallable)
	void EnableMovement(bool ShouldMove); //�Ƿ��ƶ�����
	UFUNCTION(BlueprintCallable)  
	void ResetMovement();                 //�ص�ԭλ����
	UFUNCTION(BlueprintCallable)
	void SetMoveDirection(int Direction);

};
