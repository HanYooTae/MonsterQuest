#include "Actions/Weapons/CWeapon_Guns.h"

#include "CPlayer/CPlayer.h"

ACWeapon_Guns::ACWeapon_Guns()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACWeapon_Guns::BeginPlay()
{
	Super::BeginPlay();
}

void ACWeapon_Guns::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool ACWeapon_Guns::CanFire()
{
	return false;
}

void ACWeapon_Guns::Begin_Fire()
{
}

void ACWeapon_Guns::End_Fire()
{
}

void ACWeapon_Guns::OnFiring()
{
}
