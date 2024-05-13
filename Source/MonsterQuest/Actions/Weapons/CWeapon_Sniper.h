#pragma once

#include "CoreMinimal.h"
#include "Actions/Weapons/CWeapon.h"
#include "CWeapon_Sniper.generated.h"

UCLASS()
class MONSTERQUEST_API ACWeapon_Sniper : public ACWeapon
{
	GENERATED_BODY()
	
public:
	ACWeapon_Sniper();

protected:
	virtual void BeginPlay() override;
};
