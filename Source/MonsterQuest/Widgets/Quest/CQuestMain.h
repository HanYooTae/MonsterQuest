#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CQuestMain.generated.h"

UCLASS()
class MONSTERQUEST_API UCQuestMain : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
		class UScrollbox* QuestList;

	UPROPERTY(meta = (BindWidget))
		class UGridPanel* GiftList;

	UPROPERTY(meta = (BindWidget))
		class UButton* OkButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* CancelButton;
};
