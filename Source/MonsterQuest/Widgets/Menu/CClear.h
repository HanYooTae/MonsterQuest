#pragma once

#include "CoreMinimal.h"
#include "Widgets/Menu/CMenuBase.h"
#include "CClear.generated.h"

UCLASS()
class MONSTERQUEST_API UCClear : public UCMenuBase
{
	GENERATED_BODY()
	
protected:
	virtual bool Initialize() override;

public:
	UFUNCTION()
		void QuitButtonPressed();

	UFUNCTION()
		void ContinueButtonPressed();

private:
	UPROPERTY(meta = (BindWidget))
		class UButton* ContinueButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* QuitButton;
};
