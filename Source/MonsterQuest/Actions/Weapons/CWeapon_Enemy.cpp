#include "Actions/Weapons/CWeapon_Enemy.h"

ACWeapon_Enemy::ACWeapon_Enemy()
{
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	RootComponent = Weapon;
}

void ACWeapon_Enemy::BeginPlay()
{
	Super::BeginPlay();

}