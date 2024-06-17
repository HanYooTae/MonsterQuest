#pragma once

#include "CoreMinimal.h"
#include "Actions/Reload/CReload.h"
#include "CReload_Rifle.generated.h"

UCLASS()
class MONSTERQUEST_API ACReload_Rifle : public ACReload
{
	GENERATED_BODY()
	
public:
	ACReload_Rifle();

protected:
	virtual void BeginPlay() override;
};
