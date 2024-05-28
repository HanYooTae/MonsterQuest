#pragma once

#include "CoreMinimal.h"
#include "Actions/DoActions/CDoAction_Fire.h"
#include "CDoAction_Pistol.generated.h"

UCLASS()
class MONSTERQUEST_API ACDoAction_Pistol : public ACDoAction_Fire
{
	GENERATED_BODY()

public:
	ACDoAction_Pistol();

protected:
	virtual void BeginPlay() override;
};
