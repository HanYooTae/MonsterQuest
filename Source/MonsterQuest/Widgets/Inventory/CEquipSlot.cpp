#include "Widgets/Inventory/CEquipSlot.h"

#include "CPlayer/CPlayer.h"
#include "ItemDatas/CItemData.h"

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
}
