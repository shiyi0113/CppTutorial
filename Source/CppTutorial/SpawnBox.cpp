#include "SpawnBox.h"


ASpawnBox::ASpawnBox()
{

	PrimaryActorTick.bCanEverTick = false;
	SpawnBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnBox"));
	RootComponent = SpawnBox;
}

void ASpawnBox::BeginPlay()
{
	Super::BeginPlay();
	if (ShouldSpawn) {
		ScheduleActorSpawn();
	}

}

void ASpawnBox::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
	GetWorld()->GetTimerManager().ClearTimer(SpawnTimeHandle);

}

bool ASpawnBox::SpawnActor()
{
	bool SpawnedActor = false;
	if (ActorClassToBeSpawned)
	{
		FBoxSphereBounds BoxBounds = SpawnBox->CalcBounds(GetActorTransform());
		FVector SpawnLocation = BoxBounds.Origin;
		SpawnLocation.X += -BoxBounds.BoxExtent.X + 2 * BoxBounds.BoxExtent.X * FMath::FRand();
		SpawnLocation.Y += -BoxBounds.BoxExtent.Y + 2 * BoxBounds.BoxExtent.Y * FMath::FRand();
		SpawnLocation.Z += -BoxBounds.BoxExtent.Z + 2 * BoxBounds.BoxExtent.Z * FMath::FRand();
		SpawnedActor = GetWorld()->SpawnActor(ActorClassToBeSpawned, &SpawnLocation) != nullptr;
	}
	return SpawnedActor;
}




void ASpawnBox::ScheduleActorSpawn()
{
	float DeltaToNextSpawn = AvgSpawnTime + (-RandomSpawnTimeOffset + 2 * RandomSpawnTimeOffset * FMath::FRand());
	GetWorld()->GetTimerManager().SetTimer(SpawnTimeHandle, this, &ASpawnBox::SpawnActorScheduled, DeltaToNextSpawn, false);
}
void ASpawnBox::SpawnActorScheduled()
{
	if (SpawnActor()) {
		if (ShouldSpawn) {
			ScheduleActorSpawn();
		}
	}
	else {
		//±¨´í
	}
}
void ASpawnBox::EnableActorSpawning(bool Enable)
{
	ShouldSpawn = Enable;
	if (Enable) {
		ScheduleActorSpawn();
	}
	else {
		GetWorld()->GetTimerManager().ClearTimer(SpawnTimeHandle);
	}
}
