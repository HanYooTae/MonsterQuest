#include "CInteract.h"

#include "Components/TextBlock.h"

#include "Global.h"

bool UCInteract::Initialize() {
	bool bCheck = Super::Initialize();
	CheckFalseResult(bCheck, false);

	return true;
}

void UCInteract::SetInteractText(FString Description)
{
	Interact->SetText(FText::FromString(Description));
}