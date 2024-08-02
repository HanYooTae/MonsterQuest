#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CItemDescription.generated.h"

UCLASS()
class MONSTERQUEST_API UCItemDescription : public UUserWidget
{
	GENERATED_BODY()
	
public:
	/*UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void SettingDescription(FCItemStruct item);*/

public:
	UImage* GetItemImage() { return ItemImage; }
	UTextBlock* GetItemName() { return ItemName; }
	UTextBlock* GetItemType() { return ItemType; }
	UTextBlock* GetItemDescription() { return ItemDescription; }

private:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UImage* ItemImage;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* ItemName;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* ItemType;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* ItemDescription;
};
