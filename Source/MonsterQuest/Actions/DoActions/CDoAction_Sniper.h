#pragma once

#include "CoreMinimal.h"
#include "Actions/DoActions/CDoAction_Fire.h"
#include "CDoAction_Sniper.generated.h"

UCLASS()
class MONSTERQUEST_API ACDoAction_Sniper : public ACDoAction_Fire
{
	GENERATED_BODY()
	
public:
	ACDoAction_Sniper();

protected:
	virtual void BeginPlay() override;

public:
	virtual void OnAim() override;
	virtual void OffAim() override;
};
