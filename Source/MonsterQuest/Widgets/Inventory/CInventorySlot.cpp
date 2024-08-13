#include "Widgets/Inventory/CInventorySlot.h"

#include "CPlayer/CPlayer.h"
#include "Widgets/Inventory/CInventory.h"
#include "Widgets/Inventory/CEquipSlot.h"
#include "ItemDatas/CItemData.h"

#include "Components/Image.h"

#include "Global.h"

void UCInventorySlot::NativeConstruct()
{
	Super::NativeConstruct();

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
}

void UCInventorySlot::EquipSword()
{
}

void UCInventorySlot::EquipPistol()
{
}

void UCInventorySlot::EquipRifle()
{
}

void UCInventorySlot::EquipSniper()
{
}