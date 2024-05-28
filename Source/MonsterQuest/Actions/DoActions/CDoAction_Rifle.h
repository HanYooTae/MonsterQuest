#pragma once

#include "CoreMinimal.h"
#include "Actions/DoActions/CDoAction_Fire.h"
#include "CDoAction_Rifle.generated.h"

UCLASS()
class MONSTERQUEST_API ACDoAction_Rifle : public ACDoAction_Fire
{
	GENERATED_BODY()

public:
	ACDoAction_Rifle();

protected:
	virtual void BeginPlay() override;
};
