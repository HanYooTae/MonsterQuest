#pragma once

#include "CoreMinimal.h"
#include "Actions/Weapons/CWeapon.h"
#include "CWeapon_Sword.generated.h"

UCLASS()
class MONSTERQUEST_API ACWeapon_Sword : public ACWeapon
{
	GENERATED_BODY()
	
public:
	ACWeapon_Sword();

protected:
	virtual void BeginPlay() override;

};
