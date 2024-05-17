#pragma once

#include "CoreMinimal.h"
#include "Actions/Weapons/CWeapon_Guns.h"
#include "CWeapon_Pistol.generated.h"

UCLASS()
class MONSTERQUEST_API ACWeapon_Pistol : public ACWeapon_Guns
{
	GENERATED_BODY()
	
public:
	ACWeapon_Pistol();

protected:
	virtual void BeginPlay() override;
};