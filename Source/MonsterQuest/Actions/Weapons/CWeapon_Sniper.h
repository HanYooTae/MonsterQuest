#pragma once

#include "CoreMinimal.h"
#include "Actions/Weapons/CWeapon_Guns.h"
#include "CWeapon_Sniper.generated.h"

UCLASS()
class MONSTERQUEST_API ACWeapon_Sniper : public ACWeapon_Guns
{
	GENERATED_BODY()
	
public:
	ACWeapon_Sniper();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* DotSight;
};
