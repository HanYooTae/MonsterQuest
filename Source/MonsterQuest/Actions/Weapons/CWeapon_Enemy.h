#pragma once

#include "CoreMinimal.h"
#include "Actions/Weapons/CWeapon.h"
#include "CWeapon_Enemy.generated.h"

UCLASS()
class MONSTERQUEST_API ACWeapon_Enemy : public ACWeapon
{
	GENERATED_BODY()
	
public:
	ACWeapon_Enemy();

protected:
	virtual void BeginPlay() override;
};
