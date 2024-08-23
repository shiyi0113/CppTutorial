#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "SpawnBox.generated.h"

UCLASS()
class CPPTUTORIAL_API ASpawnBox : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpawnBox();
	UFUNCTION(BlueprintCallable)
	bool SpawnActor();                //生成一个Spawn
	UFUNCTION(BlueprintCallable)
	void EnableActorSpawning(bool Enable);

protected:
	virtual void BeginPlay() override;
	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ActorClassToBeSpawned;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AvgSpawnTime = 5.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RandomSpawnTimeOffset = 1.0f;

private:
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* SpawnBox;
	UPROPERTY(EditAnywhere)
	bool ShouldSpawn = true;
	UFUNCTION()
	void SpawnActorScheduled();
	void ScheduleActorSpawn();   //调用函数SpawnActor()产生一堆Spawn
	FTimerHandle SpawnTimeHandle;

};
