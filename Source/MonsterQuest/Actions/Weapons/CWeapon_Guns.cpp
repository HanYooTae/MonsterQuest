#include "Actions/Weapons/CWeapon_Guns.h"

#include "CPlayer/CPlayer.h"
#include "Actions/Weapons/CBullet.h"

#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"

#include "Global.h"

ACWeapon_Guns::ACWeapon_Guns()
{
	PrimaryActorTick.bCanEverTick = true;

	CHelpers::CreateSceneComponent<USceneComponent>(this, &Root, "Root");
	CHelpers::CreateSceneComponent<USkeletalMeshComponent>(this, &Weapon, "Weapon", Root);
}

void ACWeapon_Guns::BeginPlay()
{
	Super::BeginPlay();
}

void ACWeapon_Guns::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}