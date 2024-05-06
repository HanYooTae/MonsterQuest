#include "Actions/Weapons/CWeapon_Sniper.h"

#include "GameFramework/Character.h"

#include "Global.h"

ACWeapon_Sniper::ACWeapon_Sniper()
{
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Sniper"));
	RootComponent = Weapon;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> WEAPON(TEXT("SkeletalMesh'/Game/Weapons/Sniper/SK_KA47.SK_KA47'"));
	if (WEAPON.Succeeded())
	{
		Weapon->SetSkeletalMesh(WEAPON.Object);
	}
}

void ACWeapon_Sniper::BeginPlay()
{
	Super::BeginPlay();

}