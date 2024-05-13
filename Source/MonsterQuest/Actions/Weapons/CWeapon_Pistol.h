#pragma once

#include "CoreMinimal.h"
#include "Actions/Weapons/CWeapon.h"
#include "CWeapon_Pistol.generated.h"

UCLASS()
class MONSTERQUEST_API ACWeapon_Pistol : public ACWeapon
{
	GENERATED_BODY()
	
public:
	ACWeapon_Pistol();

protected:
	virtual void BeginPlay() override;
};
