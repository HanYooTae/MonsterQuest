#pragma once

#include "CoreMinimal.h"
#include "Actions/Reload/CReload.h"
#include "CReload_Pistol.generated.h"

UCLASS()
class MONSTERQUEST_API ACReload_Pistol : public ACReload
{
	GENERATED_BODY()
	
public:
	ACReload_Pistol();

protected:
	virtual void BeginPlay() override;
};
