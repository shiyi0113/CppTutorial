#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/DefaultPawn.h"
#include "Components/Boxcomponent.h"
#include "MyCollectableActor.generated.h"

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnJumpTriggerSignature, AActor*, OtherActor, UPrimitiveComponent*, OtherComp);

UCLASS()
class CPPTUTORIAL_API AMyCollectableActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyCollectableActor();
	virtual void Tick(float DeltaTime) override;

private://函数
	UFUNCTION(BlueprintCallable)
	void Jump(float velocity);
	UFUNCTION(BlueprintCallable)
	void OnComponentBeginOverlap(class UBoxComponent* Component, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Velocity = 5.0f;

private://变量
	UPROPERTY(EditAnywhere) 
	UStaticMeshComponent* StaticMesh; //静态网格体
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* BoxCollision;      //碰撞盒
	UPROPERTY(EditAnywhere)
	float Livetime = 2.5f;     //存在时间
	bool IsLaunched = false;   //是否运行销毁
	UPROPERTY(EditAnywhere)
	UClass* TriggerClass = ADefaultPawn::StaticClass();
	UPROPERTY(BlueprintAssignable)
	FOnJumpTriggerSignature OnJumpTrigger;


};
