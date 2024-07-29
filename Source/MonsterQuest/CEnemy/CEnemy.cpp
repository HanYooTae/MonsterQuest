#include "CEnemy/CEnemy.h"

#include "CEnemy/CAIController.h"
#include "ActorComponents/CStatusComponent.h"
#include "ActorComponents/CStateComponent.h"
#include "ActorComponents/CMontagesComponent.h"
#include "ActorComponents/CActionComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/CapsuleComponent.h"

#include "Global.h"

ACEnemy::ACEnemy()
{
	//Create Scene Component
	/*CHelpers::CreateSceneComponent(this, &HealthWidget, "HealthWidget", GetMesh());*/

	//Create Actor Component
	CHelpers::CreateActorComponent(this, &Action, "Action");
	CHelpers::CreateActorComponent(this, &Status, "Status");
	CHelpers::CreateActorComponent(this, &Montages, "Montages");
	CHelpers::CreateActorComponent(this, &State, "State");
	//CHelpers::CreateActorComponent(this, &Patrol, "Patrol");

	//Component Settings
	// -> MeshComp
	GetMesh()->SetRelativeLocation(FVector(0, 0, -88));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

	USkeletalMesh* meshAsset;
	CHelpers::GetAsset(&meshAsset, "SkeletalMesh'/Game/Frank_Slash_Pack/Frank_RPG_GreatSword/Skeletal_Meshes/SK_Frank_RPG_GreatSword.SK_Frank_RPG_GreatSword'");
	GetMesh()->SetSkeletalMesh(meshAsset);

	TSubclassOf<UAnimInstance> animInstanceClass;
	CHelpers::GetClass(&animInstanceClass, "AnimBlueprint'/Game/Characters/Enemies/ABP_CEnemy_GreatSword.ABP_CEnemy_GreatSword_C'");
	GetMesh()->SetAnimInstanceClass(animInstanceClass);

	// -> MovementComp
	GetCharacterMovement()->RotationRate = FRotator(0, 720, 0);
	GetCharacterMovement()->MaxWalkSpeed = Status->GetRunSpeed();

	// -> WidgetComp
	/*TSubclassOf<UCEnemyHealthWidget> healthWidgetClass;
	CHelpers::GetClass(&healthWidgetClass, "WidgetBlueprint'/Game/Widget/HealthWidget/WB_CEnemyHealthWidget.WB_CEnemyHealthWidget_C'");
	HealthWidget->SetWidgetClass(healthWidgetClass);
	HealthWidget->SetRelativeLocation(FVector(0, 0, 180));
	HealthWidget->SetDrawSize(FVector2D(120, 20));
	HealthWidget->SetWidgetSpace(EWidgetSpace::Screen);*/
}

void ACEnemy::BeginPlay()
{
	Super::BeginPlay();

	Action->Type = EActionType::Sword;

	//Widget Settings
	/*HealthWidget->InitWidget();
	UCEnemyHealthWidget* healthWidget = Cast<UCEnemyHealthWidget>(HealthWidget->GetUserWidgetObject());

	if (!!healthWidget)
		healthWidget->UpdateHealth(Status->GetCurrentHealth(), Status->GetMaxHealth());*/
}

float ACEnemy::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	DamageValue = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	Attacker = EventInstigator->GetCharacter();
	Causer = DamageCauser;

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
	// Apply Health Widget
	/*UCEnemyHealthWidget* healthWidget = Cast<UCEnemyHealthWidget>(HealthWidget->GetUserWidgetObject());
	if (!!healthWidget)
		healthWidget->UpdateHealth(Status->GetCurrentHealth(), Status->GetMaxHealth());*/

	// Play Hit Montage
	Montages->PlayHitted();

	// Look at Attacker
	FVector start = GetActorLocation();
	FVector target = Attacker->GetActorLocation();
	FRotator rotation = FRotator(0, UKismetMathLibrary::FindLookAtRotation(start, target).Yaw, 0);
	SetActorRotation(rotation);

	// Hit Back
	FVector direction = (start - target).GetSafeNormal();
	LaunchCharacter(direction * LaunchValue * DamageValue, true, false);
}

void ACEnemy::Dead()
{
	CheckTrue(State->IsDeadMode());

	//HealthWidget->SetVisibility(false);

	State->SetDeadMode();

	AController* controller = this->GetController();
	controller->Destroy();

	// Play Dead Montage
	Montages->PlayDead();

	// Off All Collisions
	Action->OffAllCollisions();
	GetCapsuleComponent()->SetCollisionProfileName("Spectator");

	// Destroy All(Attachment, Equipment, DoAction...)
	Dissolve();
	UKismetSystemLibrary::K2_SetTimer(this, "End_Dead", 5.f, false);
}

void ACEnemy::End_Dead()
{
	Action->End_Dead();

	Destroy();
}