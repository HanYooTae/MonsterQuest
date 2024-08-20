#pragma once

#include "CoreMinimal.h"
#include "Widgets/Menu/CMenuBase.h"
#include "CLose.generated.h"

UCLASS()
class MONSTERQUEST_API UCLose : public UCMenuBase
{
	GENERATED_BODY()
	
protected:
	virtual bool Initialize() override;

public:
	UFUNCTION()
		void QuitButtonPressed();

private:
	UPROPERTY(meta = (BindWidget))
		class UButton* QuitButton;
};
