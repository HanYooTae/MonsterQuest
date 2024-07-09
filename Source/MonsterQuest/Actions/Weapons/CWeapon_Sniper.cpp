#include "Actions/Weapons/CWeapon_Sniper.h"

#include "GameFramework/Character.h"

#include "Global.h"

ACWeapon_Sniper::ACWeapon_Sniper()
{
	USkeletalMesh* mesh;
	CHelpers::GetAsset<USkeletalMesh>(&mesh, "SkeletalMesh'/Game/Weapons/Sniper/SK_KA47.SK_KA47'");
	Weapon->SetSkeletalMesh(mesh);

	ArmsLeftHandTransform.SetLocation(FVector(-33, 11, -1.5f));
	ArmsLeftHandTransform.SetRotation(FQuat(FRotator(-4, -138, 77)));
}

void ACWeapon_Sniper::BeginPlay()
{
	Super::BeginPlay();

}