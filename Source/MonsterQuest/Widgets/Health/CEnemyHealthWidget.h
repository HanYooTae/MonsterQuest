#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CEnemyHealthWidget.generated.h"

UCLASS()
class MONSTERQUEST_API UCEnemyHealthWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
		void UpdateHealth(float InCurrentHealth, float InMaxHealth);

private:
	UPROPERTY(meta = (BindWidget))
		class UProgressBar* HealthBar;
};
