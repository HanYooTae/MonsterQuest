#include "Actions/Weapons/CWeapon_Rifle.h"

#include "GameFramework/Character.h"

#include "Global.h"

ACWeapon_Rifle::ACWeapon_Rifle()
{
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Rifle"));
	RootComponent = Weapon;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> WEAPON(TEXT("SkeletalMesh'/Game/Weapons/Rifle/SK_AR4.SK_AR4'"));
	if (WEAPON.Succeeded())
	{
		Weapon->SetSkeletalMesh(WEAPON.Object);
	}
}

void ACWeapon_Rifle::BeginPlay()
{
	Super::BeginPlay();

}