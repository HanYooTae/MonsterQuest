#include "Widgets/Inventory/CEquipSlot.h"

#include "CPlayer/CPlayer.h"
#include "ItemDatas/CItemData.h"
#include "ActionDatas/CActionData.h"
#include "ActionDatas/CActionData_Spawned.h"
#include "Actions/Weapons/CWeapon.h"
#include "Actions/Equipment/CEquipment.h"
#include "Actions/DoActions/CDoAction.h"
#include "Actions/Reload/CReload.h"

#include "Components/Image.h"

#include "Global.h"

void UCEquipSlot::NativeConstruct()
{
	Super::NativeConstruct();

	OwnerCharacter = Cast<ACharacter>(GetOwningPlayerPawn());
	SlotImage->SetBrushFromTexture(DefaultImage);
}

void UCEquipSlot::SettingSlot(UCItemData* InItem)
{
	SlotImage->SetBrushFromTexture(InItem->Item.Picture);

	Item = InItem;
	bEquipped = true;
}

void UCEquipSlot::UnEquipItem()
{
	bEquipped = false;

	ACPlayer* player = Cast<ACPlayer>(OwnerCharacter);
	CheckNull(player);
	UCActionComponent* actionComp = player->GetAction();
	CheckNull(actionComp);

	player->AddItem(Item);
	SlotImage->SetBrushFromTexture(DefaultImage);

	switch (Item->Item.WeaponType)
	{
	case EWeaponType::Sword:
	{
		player->bSword = false;
		DeleteWeapon(EActionType::Sword);
		actionComp->SetUnarmedMode();
		break;
	}
	case EWeaponType::Pistol:
	{
		player->bPistol = false;
		DeleteWeapon(EActionType::Pistol);
		actionComp->SetUnarmedMode();
		break;
	}
	case EWeaponType::Rifle:
	{
		player->bRifle = false;
		DeleteWeapon(EActionType::Rifle);
		actionComp->SetUnarmedMode();
		break;
	}
	case EWeaponType::Sniper:
	{
		player->bSniper = false;
		DeleteWeapon(EActionType::Sniper);
		actionComp->SetUnarmedMode();
		break;
	}
	}
}

void UCEquipSlot::DeleteWeapon(EActionType InActionType)
{
	ACPlayer* player = Cast<ACPlayer>(OwnerCharacter);
	CheckNull(player);

	UCActionComponent* actionComp = player->GetAction();
	CheckNull(actionComp);

	if (!!actionComp->Datas[(int32)InActionType] && !!actionComp->Datas[(int32)InActionType]->GetEquipment())
		actionComp->Datas[(int32)InActionType]->GetEquipment()->Destroy();

	if (!!actionComp->Datas[(int32)InActionType] && !!actionComp->Datas[(int32)InActionType]->GetWeapon())
		actionComp->Datas[(int32)InActionType]->GetWeapon()->Destroy();

	if (!!actionComp->Datas[(int32)InActionType] && !!actionComp->Datas[(int32)InActionType]->GetDoAction())
		actionComp->Datas[(int32)InActionType]->GetDoAction()->Destroy();

	if (!!actionComp->Datas[(int32)InActionType] && !!actionComp->Datas[(int32)InActionType]->GetReload())
		actionComp->Datas[(int32)InActionType]->GetReload()->Destroy();
}
