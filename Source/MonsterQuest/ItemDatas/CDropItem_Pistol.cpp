#include "ItemDatas/CDropItem_Pistol.h"

#include "Global.h"

ACDropItem_Pistol::ACDropItem_Pistol()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> skeletalMesh(TEXT("SkeletalMesh'/Game/Weapons/Pistol/Pistols_A.Pistols_A'"));
	if (skeletalMesh.Succeeded())
	{
		SkeletalMesh->SetSkeletalMesh(skeletalMesh.Object);
	}
}