#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CInventory.generated.h"

UCLASS()
class MONSTERQUEST_API UCInventory : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

public:
	FORCEINLINE bool IsOpened() { return Opened; }

public:
	void Attach();
	void Detach();
	uint8 AddItem(class UCItemData* item);

private:
	void Update();

public:
	UPROPERTY(meta = (BindWidget))
		class UCEquipSlot* SwordEquipment;

	UPROPERTY(meta = (BindWidget))
		class UCEquipSlot* BowEquipment;

	UPROPERTY(meta = (BindWidget))
		class UUniformGridPanel* BagPannel;

private:
	class ACharacter* OwnerCharacter;
	bool Opened = false;
	uint32 MaxInventory = 30;
};
