#include "CEnemy/CEnemy.h"

#include "ActorComponents/CStatusComponent.h"
#include "ActorComponents/CStateComponent.h"
#include "ActorComponents/CMontagesComponent.h"
#include "ActorComponents/CEnemyActionComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/CapsuleComponent.h"

#include "Global.h"

ACEnemy::ACEnemy()
{
	// Create ActorComponents
	CHelpers::CreateActorComponent(this, &EnemyAction, "EnemyAction");
	CHelpers::CreateActorComponent(this, &Status, "Status");
	CHelpers::CreateActorComponent(this, &Montages, "Montages");
	CHelpers::CreateActorComponent(this, &State, "State");

	USkeletalMesh* meshAsset;
	CHelpers::GetAsset(&meshAsset, "SkeletalMesh'/Game/Frank_Slash_Pack/Frank_RPG_GreatSword/Skeletal_Meshes/SK_Frank_RPG_GreatSword.SK_Frank_RPG_GreatSword'");
	GetMesh()->SetSkeletalMesh(meshAsset);
	GetMesh()->SetRelativeLocation(FVector(0, 0, -88));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

}

void ACEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

float ACEnemy::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	DamageValue = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	//Attacker = EventInstigator->GetCharacter();
	//Causer = DamageCauser;

	Status->DecreaseHealth(DamageValue);

	// Dead
	if (Status->IsDead())
	{
		Dead();
		return DamageValue;
	}

	Hitted();

	return DamageValue;
}

void ACEnemy::Hitted()
{
	State->SetHittedMode();

	// Play Hit Montage
	Montages->PlayHitted();
}

void ACEnemy::Dead()
{
}

void ACEnemy::End_Dead()
{
}
