#include "Actions/Weapons/CWeapon_Rifle.h"

#include "GameFramework/Character.h"

#include "Global.h"

ACWeapon_Rifle::ACWeapon_Rifle()
{
	USkeletalMesh* mesh;
	CHelpers::GetAsset<USkeletalMesh>(&mesh, "SkeletalMesh'/Game/Weapons/Rifle/SK_AR4.SK_AR4'");
	Weapon->SetSkeletalMesh(mesh);
}

void ACWeapon_Rifle::BeginPlay()
{
	Super::BeginPlay();

}