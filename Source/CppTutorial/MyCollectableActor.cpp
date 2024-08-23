#include "MyCollectableActor.h"

AMyCollectableActor::AMyCollectableActor()
{
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMesh;
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetupAttachment(StaticMesh);

}

void AMyCollectableActor::BeginPlay()
{
	Super::BeginPlay();
	SetActorTickInterval(0.5f);   //ˢ��ʱ��ĳ�0.5sһˢ
	SetActorTickEnabled(false);
	FScriptDelegate DelegateSubscriber;
	DelegateSubscriber.BindUFunction(this, "OnComponentBeginOverlap");
	BoxCollision->OnComponentBeginOverlap.Add(DelegateSubscriber);

}

void AMyCollectableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (IsLaunched) {             //0.5sִ��һ��
		Livetime -= DeltaTime;
		if (Livetime <= 0.0f) {
			this->Destroy();
		}
	}

}

void AMyCollectableActor::Jump(float velocity)
{
	if (!IsLaunched) {
		StaticMesh->AddImpulse({ .0f,.0f,velocity * 500.f });
		SetActorTickEnabled(true);    //����ʱ��ˢ��
		IsLaunched = true;             //��������
	}

}

void AMyCollectableActor::OnComponentBeginOverlap(UBoxComponent* Component, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!IsLaunched && OtherActor->IsA(TriggerClass)) {
		OnJumpTrigger.Broadcast(OtherActor, Component);
	}
}
