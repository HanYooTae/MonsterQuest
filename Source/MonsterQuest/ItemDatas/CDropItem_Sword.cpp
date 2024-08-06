#include "ItemDatas/CDropItem_Sword.h"

#include "Global.h"

ACDropItem_Sword::ACDropItem_Sword()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> skeletalMesh(TEXT("SkeletalMesh'/Game/Weapons/Sword/SK_Straight_Sword.SK_Straight_Sword'"));
	if (skeletalMesh.Succeeded())
	{
		SkeletalMesh->SetSkeletalMesh(skeletalMesh.Object);
	}

	SkeletalMesh->SetWorldScale3D(FVector(0.3f, 0.3f, 0.3f));
}