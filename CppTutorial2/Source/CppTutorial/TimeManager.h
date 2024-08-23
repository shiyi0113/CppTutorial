#pragma once

#include "CoreMinimal.h"
#include "MathUtil.h"
#include "GameFramework/Actor.h"
#include "TimeManager.generated.h"

UCLASS()
class CPPTUTORIAL_API ATimeManager : public AActor
{
	GENERATED_BODY()
	
public:	
	ATimeManager();
	UFUNCTION(BlueprintCallable)
	float GetTimeFactor();
	UFUNCTION(BlueprintCallable)
	void BeginTimeReverse();
	UFUNCTION(BlueprintCallable)
	void EndTimeReverse();

	UFUNCTION(BlueprintCallable)
	void EnableTimeReverseAbility();
	UFUNCTION(BlueprintCallable)
	void DisableTimeReverseAbility();

	void Tick(float DeltaSeconds) override;
	UFUNCTION(BlueprintCallable)
	bool GetAbilityAvailible();
	UFUNCTION(BlueprintCallable)
	float GetCurrentReversableTime();
protected:
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintReadOnly)
	float CurrentTimeFactor = 1.0f;
	UPROPERTY(BlueprintReadOnly)
	bool TimeReversalAbilityEnabled = false;

	UPROPERTY(BlueprintReadOnly)
	float CurrentRecordedTime = 0.0f;

public:
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	float NormalTimeFactor = 1.0f;
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	float ReverseTimeFactor = -3.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ReverseTimeThreshhold = 3.0f;   //最小
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ReverseTimeMaximum = 15.0f;     //最大
};
