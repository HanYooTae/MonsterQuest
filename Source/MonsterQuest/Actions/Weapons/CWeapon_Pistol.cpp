#include "Actions/Weapons/CWeapon_Pistol.h"

#include "GameFramework/Character.h"

#include "Global.h"

ACWeapon_Pistol::ACWeapon_Pistol()
{
	USkeletalMesh* mesh;
	CHelpers::GetAsset<USkeletalMesh>(&mesh, "SkeletalMesh'/Game/Weapons/Pistol/Pistols_A.Pistols_A'");
	Weapon->SetSkeletalMesh(mesh);
}

void ACWeapon_Pistol::BeginPlay()
{
	Super::BeginPlay();

}