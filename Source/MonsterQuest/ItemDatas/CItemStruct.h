#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CItemStruct.generated.h"

UCLASS()
class MONSTERQUEST_API ACItemStruct : public AActor
{
	GENERATED_BODY()
	
public:	
	ACItemStruct();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
