#pragma once

#include "CoreMinimal.h"
#include "Actions/Reload/CReload.h"
#include "CReload_Sniper.generated.h"

UCLASS()
class MONSTERQUEST_API ACReload_Sniper : public ACReload
{
	GENERATED_BODY()
	
public:
	ACReload_Sniper();

protected:
	virtual void BeginPlay() override;
};
