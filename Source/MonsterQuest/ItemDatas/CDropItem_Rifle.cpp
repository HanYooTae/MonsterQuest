#include "ItemDatas/CDropItem_Rifle.h"

#include "Global.h"

ACDropItem_Rifle::ACDropItem_Rifle()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> skeletalMesh(TEXT("SkeletalMesh'/Game/Weapons/Rifle/SK_AR4.SK_AR4'"));
	if (skeletalMesh.Succeeded())
	{
		SkeletalMesh->SetSkeletalMesh(skeletalMesh.Object);
	}
}