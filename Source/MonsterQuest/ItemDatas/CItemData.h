#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemDatas/CItemStruct.h"
#include "CItemData.generated.h"

UCLASS()
class MONSTERQUEST_API UCItemData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Items")
		FItemStruct Item;
};
