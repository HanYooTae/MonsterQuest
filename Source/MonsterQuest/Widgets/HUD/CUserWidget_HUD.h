#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CUserWidget_HUD.generated.h"

UCLASS()
class MONSTERQUEST_API UCUserWidget_HUD : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent)
		void OnAutoFire();

	UFUNCTION(BlueprintImplementableEvent)
		void OffAutoFire();

	UFUNCTION(BlueprintImplementableEvent)
		void UpdateWeaponName(EActionType InType);

	UFUNCTION(BlueprintImplementableEvent)
		void UpdateMagazine(uint8 InCount, uint8 InMax);
};
