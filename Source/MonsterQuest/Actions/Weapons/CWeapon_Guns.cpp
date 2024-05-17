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

	CHelpers::GetClass<ACBullet>(&BulletClass, "Blueprint'/Game/Weapons/BP_CBullet.BP_CBullet_C'");
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
	return !bFiring;
}

void ACWeapon_Guns::Begin_Fire()
{
	bFiring = true;

	if (bAutoFire)
	{
		GetWorld()->GetTimerManager().SetTimer(AutoFireHandle, this, &ACWeapon_Guns::OnFiring, AutoFireInterval, true, 0);

		return;
	}

	OnFiring();
}

void ACWeapon_Guns::End_Fire()
{
	if (bAutoFire)
	{
		GetWorld()->GetTimerManager().ClearTimer(AutoFireHandle);
	}

	bFiring = false;
}

void ACWeapon_Guns::OnFiring()
{
	UCameraComponent* camera = CHelpers::GetComponent<UCameraComponent>(GetOwner());
	FVector direction = camera->GetForwardVector();
	FTransform transform = camera->GetComponentToWorld();

	FVector muzzleLocation = Weapon->GetSocketLocation(MuzzleBoneName);

	if (!!BulletClass)
	{
		FVector spawnLocation = muzzleLocation + direction * 100;

		ACBullet* bullet = GetWorld()->SpawnActor<ACBullet>(BulletClass, spawnLocation, direction.Rotation());
	}
}
