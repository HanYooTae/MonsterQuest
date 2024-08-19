#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CPlayerHealthWidget.generated.h"

UCLASS()
class MONSTERQUEST_API UCPlayerHealthWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

public:
	UFUNCTION(BlueprintCallable)
		void UpdateHealth();

private:
	UPROPERTY(meta = (BindWidget))
		class UProgressBar* HealthBar;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* CurrentHealthText;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* MaxHealthText;

private:
	class UCStatusComponent* StatusComp;
	FString CurrentHealthStr;
	FString MaxHealthStr;
};
