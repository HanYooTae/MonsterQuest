#pragma once

#include "CoreMinimal.h"
#include "Actions/Weapons/CWeapon.h"
#include "CWeapon_Guns.generated.h"

UCLASS()
class MONSTERQUEST_API ACWeapon_Guns : public ACWeapon
{
	GENERATED_BODY()
	
public:
	ACWeapon_Guns();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

};
