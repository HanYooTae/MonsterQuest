#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CInteract.generated.h"

UCLASS()
class MONSTERQUEST_API UCInteract : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual bool Initialize() override;

public:
	void SetInteractText(FString Description);

private:
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* Interact;
};
