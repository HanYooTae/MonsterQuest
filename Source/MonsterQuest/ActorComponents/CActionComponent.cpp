#include "ActorComponents/CActionComponent.h"

#include "ActionDatas/CActionData_Spawned.h"
#include "ActionDatas/CActionData.h"
#include "Actions/Equipment/CEquipment.h"
#include "Actions/DoActions/CDoAction.h"
#include "Actions/Weapons/CWeapon.h"

#include "GameFramework/Character.h"

#include "Global.h"

UCActionComponent::UCActionComponent()
{
}

void UCActionComponent::BeginPlay()
{
	Super::BeginPlay();

	ACharacter* ownerCharacter = Cast<ACharacter>(GetOwner());

	for (int32 i = 0; i < (int32)EActionType::Max; i++)
	{
		if (!!DataAssets[i])
			DataAssets[i]->BeginPlay(ownerCharacter, &Datas[i]);
	}
}

void UCActionComponent::SetUnarmedMode()
{
	// 무기 해제
	if (!!Datas[(int32)Type] && !!Datas[(int32)Type]->GetEquipment())
		Datas[(int32)Type]->GetEquipment()->Unequip();

	ChangeType(EActionType::Unarmed);
}

void UCActionComponent::SetSwordMode()
{
	SetMode(EActionType::Sword);
}

void UCActionComponent::SetPistolMode()
{
	SetMode(EActionType::Pistol);
}

void UCActionComponent::SetRifleMode()
{
	SetMode(EActionType::Rifle);
}

void UCActionComponent::SetSniperMode()
{
	SetMode(EActionType::Sniper);
}

void UCActionComponent::SetMode(EActionType InNewType)
{
	// 같은 키를 2번 눌렀을 때
	if (Type == InNewType)
	{
		SetUnarmedMode();

		return;
	}

	// Unarmed가 아닌 Type을 장착하고 있었다면
	else if (IsUnarmedMode() == false)
	{
		// 이전 무기 장착 해제
		if (!!Datas[(int32)Type] && !!Datas[(int32)Type]->GetEquipment())
			Datas[(int32)Type]->GetEquipment()->Unequip();
	}
	// 새로운 무기 장착
	if (!!Datas[(int32)InNewType] && !!Datas[(int32)InNewType]->GetEquipment())
		Datas[(int32)InNewType]->GetEquipment()->Equip();

	ChangeType(InNewType);
}

void UCActionComponent::ChangeType(EActionType InNewType)
{
	Type = InNewType;

	if (OnActionTypeChanged.IsBound())
		OnActionTypeChanged.Broadcast(InNewType);
}

void UCActionComponent::DoAction()
{
	CheckTrue(IsUnarmedMode());

	if (!!GetCurrentData())
	{
		ACDoAction* doAction = GetCurrentData()->GetDoAction();
		if (!!doAction)
		{
			doAction->DoAction();
		}
	}
}

void UCActionComponent::DoAim(bool InPressed)
{
}

void UCActionComponent::OffAllCollisions()
{
	for (const auto& data : Datas)
	{
		if (data == nullptr)
			continue;

		if (data->GetWeapon() == nullptr)
			continue;

		data->GetWeapon()->OffCollision();
	}
}

void UCActionComponent::End_Dead()
{
	for (int32 i = 0; i < (int32)EActionType::Max; i++)
	{
		if (!!Datas[i] && !!Datas[i]->GetEquipment())
			Datas[i]->GetEquipment()->Destroy();

		if (!!Datas[i] && !!Datas[i]->GetWeapon())
			Datas[i]->GetWeapon()->Destroy();

		if (!!Datas[i] && !!Datas[i]->GetDoAction())
			Datas[i]->GetDoAction()->Destroy();
	}
}
