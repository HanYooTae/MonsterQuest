#include "Widgets/Inventory/CInventory.h"

#include "CPlayer/CPlayer.h"
#include "Widgets/Inventory/CInventorySlot.h"
#include "Widgets/Inventory/CEquipSlot.h"
#include "ItemDatas/CItemData.h"

#include "Components/UniformGridPanel.h"

#include "Global.h"

void UCInventory::NativeConstruct()
{
	Super::NativeConstruct();

}

void UCInventory::Attach()
{
	bVisible = true;
	SetVisibility(ESlateVisibility::Visible);

	FInputModeGameAndUI inputMode;
	inputMode.SetWidgetToFocus(TakeWidget());

	UWorld* world = GetWorld();
	CheckNull(world);

	APlayerController* controller = world->GetFirstPlayerController();
	CheckNull(controller);

	controller->bShowMouseCursor = true;
	controller->SetInputMode(inputMode);
}

void UCInventory::Detach()
{
	bVisible = false;
	SetVisibility(ESlateVisibility::Hidden);

	FInputModeGameOnly inputMode;

	UWorld* world = GetWorld();
	CheckNull(world);
	APlayerController* controller = world->GetFirstPlayerController();
	CheckNull(controller);

	controller->bShowMouseCursor = false;
	controller->SetInputMode(inputMode);
}

uint8 UCInventory::AddItem(UCItemData* item)
{
	for (uint8 i = 0; i < InventorySlot; i++)
	{
		UCInventorySlot* slot = Cast<UCInventorySlot>(BagPannel->GetChildAt(i));
		if (slot->IsFilled() == false)
		{
			slot->SettingSlot(item);
			
			return i;
		}
	}
	return -1;
}