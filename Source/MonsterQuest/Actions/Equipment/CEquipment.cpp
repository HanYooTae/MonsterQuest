#include "Actions/Equipment/CEquipment.h"
#include "ActorComponents/CStatusComponent.h"
#include "ActorComponents/CStateComponent.h"

#include "CPlayer/CPlayer.h"
#include "Widgets/HUD/CUserWidget_CrossHair.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Global.h"

ACEquipment::ACEquipment() {}

void ACEquipment::BeginPlay()
{
	Super::BeginPlay();
	
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	Player = Cast<ACPlayer>(OwnerCharacter);

	StateComp = CHelpers::GetComponent<UCStateComponent>(OwnerCharacter);
	StatusComp = CHelpers::GetComponent<UCStatusComponent>(OwnerCharacter);
}

void ACEquipment::Equip_Implementation()
{
	// Set State Equip
	StateComp->SetEquipMode();

	// bCanMove
	EquipmentData.bCanMove ? StatusComp->SetMove() : StatusComp->SetStop();

	// Play Draw Montage
	if (!!EquipmentData.AnimMontage)
	{
		OwnerCharacter->PlayAnimMontage(EquipmentData.AnimMontage, EquipmentData.PlayRate, EquipmentData.StartSection);
	}

	else
	{
		// ��Ÿ�ְ� ���� ���� ���� ��
		Begin_Equip();

		// ��Ÿ�ְ� ������ Notify�� �����Ƿ� �ٷ� SetIdle
		End_Equip();
	}

	// bPawnControl
	if (EquipmentData.bPawnControl == true)
	{
		OwnerCharacter->bUseControllerRotationYaw = true;
		OwnerCharacter->GetCharacterMovement()->bOrientRotationToMovement = false;
	}
}

void ACEquipment::Begin_Sword_Equip_Implementation()
{
	if (OnBeginSwordEquip.IsBound())
		OnBeginSwordEquip.Broadcast();
}

void ACEquipment::Begin_Equip_Implementation()
{	
	if (!!Player->CrossHair)
		Player->CrossHair->SetVisibility(ESlateVisibility::Visible);

	if (OnBeginEquip.IsBound())
		OnBeginEquip.Broadcast();
}

void ACEquipment::End_Equip_Implementation()
{
	StateComp->SetIdleMode();
	StatusComp->SetMove();
}

void ACEquipment::Unequip_Implementation()
{
	OwnerCharacter->bUseControllerRotationYaw = false;
	OwnerCharacter->GetCharacterMovement()->bOrientRotationToMovement = true;

	if (!!Player->CrossHair)
		Player->CrossHair->SetVisibility(ESlateVisibility::Hidden);

	if (OnUnequip.IsBound())
		OnUnequip.Broadcast();
}