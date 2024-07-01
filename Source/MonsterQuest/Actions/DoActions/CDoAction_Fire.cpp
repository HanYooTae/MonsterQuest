#include "Actions/DoActions/CDoAction_Fire.h"

#include "ActorComponents/CActionComponent.h"
#include "ActorComponents/CStateComponent.h"
#include "ActorComponents/CStatusComponent.h"
#include "Actions/Weapons/CBullet.h"
#include "Actions/Weapons/CWeapon.h"
#include "Actions/Reload/CReload.h"
#include "Actions/Aim/CAim_Rifle.h"

#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Camera/CameraShake.h"
#include "Sound/SoundWave.h"
#include "Particles/ParticleSystem.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Components/DecalComponent.h"

#include "Global.h"

ACDoAction_Fire::ACDoAction_Fire()
{
	CHelpers::GetAsset<USoundWave>(&FireSound, "SoundWave'/Game/Sounds/S_RifleShoot.S_RifleShoot'");

	CHelpers::GetAsset<UParticleSystem>(&EjectParticle, "ParticleSystem'/Game/Effects/P_Eject_bullet.P_Eject_bullet'");
	CHelpers::GetAsset<UParticleSystem>(&FlashParticle, "ParticleSystem'/Game/Effects/P_Muzzleflash.P_Muzzleflash'");
	CHelpers::GetAsset<UParticleSystem>(&HitParticle, "ParticleSystem'/Game/Effects/P_Impact_Default.P_Impact_Default'");

	CHelpers::GetAsset<UMaterialInstanceConstant>(&HitDecal, "MaterialInstanceConstant'/Game/Materials/M_Decal_Inst.M_Decal_Inst'");
}

void ACDoAction_Fire::BeginPlay()
{
	Super::BeginPlay();

}

void ACDoAction_Fire::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*if (LastAddSpreadTime >= 0.0f)
	{
		if (GetWorld()->GetTimeSeconds() - LastAddSpreadTime >= AutoFireInterval + 0.25f)
		{
			CurrSpreadRadius = 0;
			LastAddSpreadTime = 0;

			if (!!CrossHair)
				CrossHair->UpdateSpreadRange(CurrSpreadRadius, MaxSpreadAlignment);
		}
	}*/
}

void ACDoAction_Fire::DoAction()
{
	CheckFalse(Datas.Num() > 0);

	bCanEndAttack = true;

	CheckFalse(StateComp->IsIdleMode());
	StateComp->SetActionMode();

	Datas[0].bCanMove ? StatusComp->SetMove() : StatusComp->SetStop();

	if (!!Datas[0].AnimMontage)
	{
		OwnerCharacter->PlayAnimMontage(Datas[0].AnimMontage, Datas[0].PlayRate, Datas[0].StartSection);
	}

	CheckTrue(bFiring);

	bFiring = true;

	// 연사모드
	if (bAutoFire)
	{
		GetWorld()->GetTimerManager().SetTimer(AutoFireHandle, this, &ACDoAction_Fire::Begin_DoAction, AutoFireInterval, true);

		return;
	}

	else
	{
		// 몽타주가 없는 공격 시
		Begin_DoAction();

		// 몽타주가 없으니 Notify도 없으므로 바로 SetIdle
		End_DoAction();
	}
}

void ACDoAction_Fire::Begin_DoAction()
{
	// Spawn Projectile
	CheckNull(Datas[0].ProjectileClass);

	// 카메라의 위치, 회전
	UCameraComponent* camera = CHelpers::GetComponent<UCameraComponent>(OwnerCharacter);

	FVector direction = camera->GetForwardVector();
	FTransform transform = camera->GetComponentToWorld();

	FVector start = transform.GetLocation() + direction;

	direction = UKismetMathLibrary::RandomUnitVectorInConeInDegrees(direction, RecoilAngle);

	FVector end = transform.GetLocation() + direction * HitDistance;

	TArray<AActor*> ignores;
	ignores.Add(OwnerCharacter);

	FHitResult hitResult;
	UKismetSystemLibrary::LineTraceSingle(GetWorld(), start, end, ETraceTypeQuery::TraceTypeQuery1, false, ignores, EDrawDebugTrace::None, hitResult, true);

	if (hitResult.bBlockingHit)
	{
		FRotator rotator = hitResult.ImpactNormal.Rotation();

		if (!!HitDecal)
		{
			UDecalComponent* decal = UGameplayStatics::SpawnDecalAtLocation(GetWorld(), HitDecal, FVector(5), hitResult.Location, rotator, 10);
			decal->SetFadeScreenSize(0);
		}

		if (!!HitParticle)
		{
			FRotator impactRotation = UKismetMathLibrary::FindLookAtRotation(hitResult.Location, hitResult.TraceStart);
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), HitParticle, hitResult.Location, impactRotation);
		}
	}

	FVector muzzleLocation = Weapon->Weapon->GetSocketLocation(MuzzleBoneName);

	CLog::Log(MuzzleBoneName.ToString());

	if (!!BulletClass)
	{
		FVector spawnLocation = muzzleLocation + direction * 100;

		ACBullet* bullet = GetWorld()->SpawnActor<ACBullet>(BulletClass, spawnLocation, direction.Rotation());
		bullet->Shoot(direction);
	}

	// Sound
	if (!!FireSound)
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), FireSound, muzzleLocation);

	// Camera Shake
	TSubclassOf<UMatineeCameraShake> shakeClass = Datas[0].ShakeClass;
	if (!!shakeClass)
	{
		APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		CheckNull(controller);
		controller->PlayerCameraManager->StartCameraShake(shakeClass);
	}

	CurrMagazineCount--;

	if (CurrMagazineCount <= 0)
		Reload->Reload();


	if (!!EjectParticle)
		UGameplayStatics::SpawnEmitterAttached(EjectParticle, Weapon->Weapon, "b_gun_shelleject", FVector::ZeroVector, FRotator::ZeroRotator, EAttachLocation::KeepRelativeOffset);

	if (!!FlashParticle)
		UGameplayStatics::SpawnEmitterAttached(FlashParticle, Weapon->Weapon, "Muzzle", FVector::ZeroVector, FRotator::ZeroRotator, EAttachLocation::KeepRelativeOffset);



	// 충돌처리
	//Bullet->OnBeginOverlap.AddDynamic(this, &ACDoAction_Fire::OnBulletBeginOverlap);
}

void ACDoAction_Fire::End_DoAction()
{
	bFiring = false;

	StateComp->SetIdleMode();
	StatusComp->SetMove();

	if (bAutoFire && AutoFireHandle.IsValid())
		GetWorld()->GetTimerManager().ClearTimer(AutoFireHandle);
}

void ACDoAction_Fire::Load_Magazine()
{
	CurrMagazineCount = Datas[0].MaxMagazineCount;
}

void ACDoAction_Fire::OnBulletBeginOverlap(FHitResult hitResult)
{
	FDamageEvent damageEvent;
	hitResult.GetActor()->TakeDamage
	(
		Datas[0].Power,
		damageEvent,
		OwnerCharacter->GetController(),
		Bullet
	);
}
