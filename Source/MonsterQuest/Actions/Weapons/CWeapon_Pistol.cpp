#include "Actions/Weapons/CWeapon_Pistol.h"

#include "GameFramework/Character.h"

#include "Global.h"

ACWeapon_Pistol::ACWeapon_Pistol()
{
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Pistol"));
	RootComponent = Weapon;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> WEAPON(TEXT("SkeletalMesh'/Game/Weapons/Pistol/Pistols_A.Pistols_A'"));
	if (WEAPON.Succeeded())
	{
		Weapon->SetSkeletalMesh(WEAPON.Object);
	}
}

void ACWeapon_Pistol::BeginPlay()
{
	Super::BeginPlay();

}