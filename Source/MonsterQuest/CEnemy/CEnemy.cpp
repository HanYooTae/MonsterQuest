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