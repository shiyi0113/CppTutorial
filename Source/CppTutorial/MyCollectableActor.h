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

private://����
	UFUNCTION(BlueprintCallable)
	void Jump(float velocity);
	UFUNCTION(BlueprintCallable)
	void OnComponentBeginOverlap(class UBoxComponent* Component, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Velocity = 5.0f;

private://����
	UPROPERTY(EditAnywhere) 
	UStaticMeshComponent* StaticMesh; //��̬������
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* BoxCollision;      //��ײ��
	UPROPERTY(EditAnywhere)
	float Livetime = 2.5f;     //����ʱ��
	bool IsLaunched = false;   //�Ƿ���������
	UPROPERTY(EditAnywhere)
	UClass* TriggerClass = ADefaultPawn::StaticClass();
	UPROPERTY(BlueprintAssignable)
	FOnJumpTriggerSignature OnJumpTrigger;


};
