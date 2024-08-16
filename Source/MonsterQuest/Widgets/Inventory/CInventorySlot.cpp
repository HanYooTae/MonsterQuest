#include "Widgets/Inventory/CInventorySlot.h"

#include "CPlayer/CPlayer.h"
#include "Widgets/Inventory/CInventory.h"
#include "Widgets/Inventory/CEquipSlot.h"
#include "ItemDatas/CItemData.h"
#include "ActorComponents/CActionComponent.h"
#include "ActionDatas/CActionData.h"
#include "ActionDatas/CActionData_Spawned.h"
#include "Actions/Weapons/CWeapon.h"

#include "Components/Image.h"

#include "Global.h"

void UCInventorySlot::NativeConstruct()
{
	Super::NativeConstruct();

	OwnerCharacter = Cast<ACharacter>(GetOwningPlayerPawn());
	ACPlayer* player = Cast<ACPlayer>(OwnerCharacter);
	Inventory = player->GetInventory();
}

void UCInventorySlot::SettingSlot(UCItemData* InItem)
{
	Item = InItem;
	bFilled = true;

	SlotImage->SetBrushFromTexture(Item->Item.Picture);
	SlotImage->SetBrushSize(FVector2D(32.0f));
	SlotImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));
}

void UCInventorySlot::EquipItem()
{
	switch (Item->Item.WeaponType)
	{
		case EWeaponType::Sword:
		{
			EquipSword();
			break;
		}
		case EWeaponType::Pistol:
		{
			EquipPistol();
			break;
		}
		case EWeaponType::Rifle:
		{
			EquipRifle();
			break;
		}
		case EWeaponType::Sniper:
		{
			EquipSniper();
			break;
		}
	}
}

void UCInventorySlot::EquipSword()
{
	ACPlayer* player = Cast<ACPlayer>(OwnerCharacter);
	CheckNull(player);

	player->bSword = true;

	UCActionData* actionData = player->GetAction()->DataAssets[(int32)EActionType::Sword];
	CheckNull(actionData);

	Inventory->SwordEquipment->SettingSlot(Item);
	player->RemoveInventoryItem(Item);
	SlotImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.0f));
	bFilled = false;

	actionData->SpawnPlayerItem(OwnerCharacter, &player->GetAction()->Datas[(int32)EActionType::Sword]);
}

void UCInventorySlot::EquipPistol()
{
	ACPlayer* player = Cast<ACPlayer>(OwnerCharacter);
	CheckNull(player);

	player->bPistol = true;

	UCActionData* actionData = player->GetAction()->DataAssets[(int32)EActionType::Pistol];
	CheckNull(actionData);

	Inventory->PistolEquipment->SettingSlot(Item);
	player->RemoveInventoryItem(Item);
	SlotImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.0f));
	bFilled = false;

	actionData->SpawnPlayerItem(OwnerCharacter, &player->GetAction()->Datas[(int32)EActionType::Pistol]);
}

void UCInventorySlot::EquipRifle()
{
	ACPlayer* player = Cast<ACPlayer>(OwnerCharacter);
	CheckNull(player);

	player->bRifle = true;

	UCActionData* actionData = player->GetAction()->DataAssets[(int32)EActionType::Rifle];
	CheckNull(actionData);

	Inventory->RifleEquipment->SettingSlot(Item);
	player->RemoveInventoryItem(Item);
	SlotImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.0f));
	bFilled = false;

	actionData->SpawnPlayerItem(OwnerCharacter, &player->GetAction()->Datas[(int32)EActionType::Rifle]);
}

void UCInventorySlot::EquipSniper()
{
	ACPlayer* player = Cast<ACPlayer>(OwnerCharacter);
	CheckNull(player);

	player->bSniper = true;

	UCActionData* actionData = player->GetAction()->DataAssets[(int32)EActionType::Sniper];
	CheckNull(actionData);

	Inventory->SniperEquipment->SettingSlot(Item);
	player->RemoveInventoryItem(Item);
	SlotImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.0f));
	bFilled = false;

	actionData->SpawnPlayerItem(OwnerCharacter, &player->GetAction()->Datas[(int32)EActionType::Sniper]);
}