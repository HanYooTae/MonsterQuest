#pragma once

#include "CoreMinimal.h"
#include "Actions/Weapons/CWeapon.h"
#include "CWeapon_Rifle.generated.h"

UCLASS()
class MONSTERQUEST_API ACWeapon_Rifle : public ACWeapon
{
	GENERATED_BODY()
	
public:
	ACWeapon_Rifle();

protected:
	virtual void BeginPlay() override;
};
