#include "Actions/DoActions/CDoAction_Sword.h"

#include "GameFramework/Character.h"
#include "Sound/SoundWave.h"

#include "ActorComponents/CStateComponent.h"
#include "ActorComponents/CStatusComponent.h"

#include "Global.h"

ACDoAction_Sword::ACDoAction_Sword()
{
	CHelpers::GetAsset<USoundWave>(&SwordSound, "SoundWave'/Game/Sounds/PaladinAttackVoice.PaladinAttackVoice'");
	CHelpers::GetAsset<USoundWave>(&FinishComboSound, "SoundWave'/Game/Sounds/wield.wield'");
}

void ACDoAction_Sword::DoAction()
{
	Super::DoAction();

	CheckFalse(Datas.Num() > 0);

	bCanEndAttack = false;

	// Combo Flag
	if (bCanCombo == true)
	{
		bCanCombo = false;
		bSucceed = true;

		return;
	}

	// 공격을 하는 상태가 아니라면 return
	CheckFalse(StateComp->IsIdleMode());

	StateComp->SetActionMode();

	// 첫 번째 액션(공격) 몽타주 재생
	OwnerCharacter->PlayAnimMontage(Datas[0].AnimMontage, Datas[0].PlayRate, Datas[0].StartSection);
	Datas[0].bCanMove ? StatusComp->SetMove() : StatusComp->SetStop();
}

void ACDoAction_Sword::Begin_DoAction()
{
	Super::Begin_DoAction();

	if (!!SwordSound)
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), SwordSound, GetActorLocation());

	if (ComboCount != 2 && !!FinishComboSound)
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), FinishComboSound, GetActorLocation());

	CheckFalse(bSucceed);
	bSucceed = false;

	ComboCount++;
	ComboCount = FMath::Clamp(ComboCount, 0, Datas.Num() - 1);
	OwnerCharacter->PlayAnimMontage(Datas[ComboCount].AnimMontage, Datas[ComboCount].PlayRate, Datas[ComboCount].StartSection);
	Datas[ComboCount].bCanMove ? StatusComp->SetMove() : StatusComp->SetStop();

	CLog::Log(ComboCount);
}

void ACDoAction_Sword::End_DoAction()
{
	Super::End_DoAction();

	ComboCount = 0;

	StateComp->SetIdleMode();
	StatusComp->SetMove();
}

void ACDoAction_Sword::OnBeginOverlap(ACharacter* InAttacker, AActor* InCauser, ACharacter* InOtherCharacter)
{
	Super::OnBeginOverlap(InAttacker, InCauser, InOtherCharacter);

	// HitStop(해당 무기로 때리면 or 맞으면 일정 시간동안 설정한 배속으로 플레이됨
	float hitStop = Datas[ComboCount].HitStop;
	if (FMath::IsNearlyZero(hitStop) == false)
	{
		UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 0.02f);
		UKismetSystemLibrary::K2_SetTimer(this, "RestoreTimeDilation", 0.02f * hitStop, false);
	}

	// Camera Shake
	TSubclassOf<UMatineeCameraShake> shakeClass = Datas[ComboCount].ShakeClass;
	if (!!shakeClass)
	{
		APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		CheckNull(controller);
		controller->PlayerCameraManager->StartCameraShake(shakeClass);
	}
	// 다단히트 방지
	int32 hittedCharactersNum = HittedCharacters.Num();
	HittedCharacters.AddUnique(InOtherCharacter);
	CheckFalse(hittedCharactersNum < HittedCharacters.Num());

	// Play Particles
	UParticleSystem* effect = Datas[ComboCount].Effect;
	CheckNull(effect);
	FTransform transform = Datas[ComboCount].EffectTransform;
	transform.AddToTranslation(InOtherCharacter->GetActorLocation());

	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), effect, transform);

	FDamageEvent damageEvent;
	InOtherCharacter->TakeDamage(Datas[ComboCount].Power, damageEvent, InAttacker->GetController(), InCauser);
}

void ACDoAction_Sword::OnEndOverlap(ACharacter* InAttacker, AActor* InCauser, ACharacter* InOtherCharacter)
{
	Super::OnEndOverlap(InAttacker, InCauser, InOtherCharacter);

}

void ACDoAction_Sword::RestoreTimeDilation()
{
	UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 1.f);
}