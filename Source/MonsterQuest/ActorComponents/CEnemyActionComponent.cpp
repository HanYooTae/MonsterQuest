#include "ActorComponents/CEnemyActionComponent.h"

#include "ActionDatas/CActionData_Spawned.h"
#include "ActionDatas/CActionData.h"
#include "Actions/Equipment/CEquipment.h"
#include "Actions/DoActions/CDoAction.h"
#include "Actions/Reload/CReload.h"
#include "Actions/Weapons/CWeapon.h"

#include "GameFramework/Character.h"

#include "Global.h"

UCEnemyActionComponent::UCEnemyActionComponent() {}

void UCEnemyActionComponent::BeginPlay()
{
	Super::BeginPlay();

	ACharacter* ownerCharacter = Cast<ACharacter>(GetOwner());

	for (int32 i = 0; i < (int32)EActionType::Max; i++)
	{
		if (!!DataAssets[i])
			DataAssets[i]->BeginPlay(ownerCharacter, &Datas[i]);
	}
}

void UCEnemyActionComponent::SetUnarmedMode()
{
	// ���� ����
	if (!!Datas[(int32)Type] && !!Datas[(int32)Type]->GetEquipment())
		Datas[(int32)Type]->GetEquipment()->Unequip();

	ChangeType(EEnemyActionType::Unarmed);
}

void UCEnemyActionComponent::SetSwordMode()
{
	SetMode(EEnemyActionType::Sword);
}

void UCEnemyActionComponent::SetMode(EEnemyActionType InNewType)
{
	// ���� Ű�� 2�� ������ ��
	if (Type == InNewType)
	{
		SetUnarmedMode();

		return;
	}

	// Unarmed�� �ƴ� Type�� �����ϰ� �־��ٸ�
	else if (IsUnarmedMode() == false)
	{
		// ���� ���� ���� ����
		if (!!Datas[(int32)Type] && !!Datas[(int32)Type]->GetEquipment())
			Datas[(int32)Type]->GetEquipment()->Unequip();
	}
	// ���ο� ���� ����
	if (!!Datas[(int32)InNewType] && !!Datas[(int32)InNewType]->GetEquipment())
		Datas[(int32)InNewType]->GetEquipment()->Equip();

	ChangeType(InNewType);
}

void UCEnemyActionComponent::ChangeType(EEnemyActionType InNewType)
{
	Type = InNewType;

	if (OnEnemyActionTypeChanged.IsBound())
		OnEnemyActionTypeChanged.Broadcast(InNewType);
}

void UCEnemyActionComponent::DoAction()
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

void UCEnemyActionComponent::OffAllCollisions()
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

void UCEnemyActionComponent::End_Dead()
{
	for (int32 i = 0; i < (int32)EActionType::Max; i++)
	{
		if (!!Datas[i] && !!Datas[i]->GetEquipment())
			Datas[i]->GetEquipment()->Destroy();

		if (!!Datas[i] && !!Datas[i]->GetWeapon())
			Datas[i]->GetWeapon()->Destroy();

		if (!!Datas[i] && !!Datas[i]->GetDoAction())
			Datas[i]->GetDoAction()->Destroy();

		if (!!Datas[i] && !!Datas[i]->GetReload())
			Datas[i]->GetReload()->Destroy();
	}
}
