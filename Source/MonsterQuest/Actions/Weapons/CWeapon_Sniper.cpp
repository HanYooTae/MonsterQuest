#include "Actions/Weapons/CWeapon_Sniper.h"

#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"

#include "Global.h"

ACWeapon_Sniper::ACWeapon_Sniper()
{
	USkeletalMesh* mesh;
	CHelpers::GetAsset<USkeletalMesh>(&mesh, "SkeletalMesh'/Game/Weapons/Sniper/SK_KA47.SK_KA47'");
	Weapon->SetSkeletalMesh(mesh);

	/*CHelpers::CreateSceneComponent<UStaticMeshComponent>(this, &DotSight, "DotSight", Weapon);

	UStaticMesh* staticMesh;
	CHelpers::GetAsset<UStaticMesh>(&staticMesh, "StaticMesh'/Game/Weapons/Accessories/SM_T4_Sight.SM_T4_Sight'");
	DotSight->SetStaticMesh(staticMesh);
	DotSight->SetRelativeScale3D(FVector(1, 0.95f, 1));*/

	ArmsLeftHandTransform.SetLocation(FVector(-33, 11, -1.5f));
	ArmsLeftHandTransform.SetRotation(FQuat(FRotator(-4, -138, 77)));
}

void ACWeapon_Sniper::BeginPlay()
{
	Super::BeginPlay();

}