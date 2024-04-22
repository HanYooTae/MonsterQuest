#include "Actions/Weapons/CWeapon_Sword.h"

#include "GameFramework/Character.h"

#include "Global.h"

ACWeapon_Sword::ACWeapon_Sword()
{
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Sword"));
	RootComponent = Weapon;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> WEAPON(TEXT("SkeletalMesh'/Game/Weapons/Sword/SK_Straight_Sword.SK_Straight_Sword'"));
	if (WEAPON.Succeeded())
	{
		Weapon->SetSkeletalMesh(WEAPON.Object);
	}
}

void ACWeapon_Sword::BeginPlay()
{
	Super::BeginPlay();

}