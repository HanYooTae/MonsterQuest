#include "ItemDatas/CItemStruct.h"

#include "Global.h"

ACItemStruct::ACItemStruct()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACItemStruct::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACItemStruct::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}