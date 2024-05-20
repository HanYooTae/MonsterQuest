#include "Actions/DoActions/CDoAction_Fire.h"

#include "ActorComponents/CActionComponent.h"
#include "ActorComponents/CStateComponent.h"
#include "ActorComponents/CStatusComponent.h"
#include "Actions/Weapons/CBullet.h"

#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"

#include "Global.h"

ACDoAction_Fire::ACDoAction_Fire()
{

}

void ACDoAction_Fire::BeginPlay()
{
	Super::BeginPlay();

}

void ACDoAction_Fire::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACDoAction_Fire::DoAction()
{
	CheckFalse(Datas.Num() > 0);

	CheckFalse(StateComp->IsIdleMode());
	StateComp->SetActionMode();

	Datas[0].bCanMove ? StatusComp->SetMove() : StatusComp->SetStop();

	// DoAction Montage / 뺄 예정
	OwnerCharacter->PlayAnimMontage(Datas[0].AnimMontage, Datas[0].PlayRate, Datas[0].StartSection);
}

void ACDoAction_Fire::Begin_DoAction()
{
	// Spawn Projectile
	CheckNull(Datas[0].ProjectileClass);

	//// 카메라의 위치, 회전
	//UCameraComponent* camera = CHelpers::GetComponent<UCameraComponent>(OwnerCharacter);

	//FVector direction = camera->GetForwardVector();
	//FTransform transform = camera->GetComponentToWorld();

	//FVector start = transform.GetLocation() + direction;

	//direction = UKismetMathLibrary::RandomUnitVectorInConeInDegrees(direction, 0.75f);

	//FVector end = transform.GetLocation() + direction * 3000;

	FVector location;
	FRotator rotation;
	OwnerCharacter->GetController()->GetPlayerViewPoint(location, rotation);

	FVector handSocketLocation = OwnerCharacter->GetMesh()->GetSocketLocation("Hand_Test");
	FVector cameraDirection = rotation.Vector();

	location += cameraDirection * ((handSocketLocation - location) | cameraDirection);

	FTransform transform = Datas[0].EffectTransform;
	transform.AddToTranslation(location);

	transform.SetRotation(FQuat(OwnerCharacter->GetControlRotation()));		// != OwnerCharacter->GetActorForwardVector()->Rotation()

	Bullet = GetWorld()->SpawnActorDeferred<ACBullet>
	(
		Datas[0].ProjectileClass,
		transform,
		OwnerCharacter,
		OwnerCharacter,
		ESpawnActorCollisionHandlingMethod::AlwaysSpawn
	);

	Bullet->FinishSpawning(transform);

	// 충돌처리
	Bullet->OnBeginOverlap.AddDynamic(this, &ACDoAction_Fire::OnBulletBeginOverlap);
}

void ACDoAction_Fire::End_DoAction()
{
	StateComp->SetIdleMode();
	StatusComp->SetMove();
}

void ACDoAction_Fire::OnBulletBeginOverlap(FHitResult hitResult)
{
	FDamageEvent damageEvent;
	hitResult.GetActor()->TakeDamage
	(
		Datas[0].power,
		damageEvent,
		OwnerCharacter->GetController(),
		Bullet
	);
}
