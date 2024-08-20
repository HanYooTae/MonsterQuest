#include "Widgets/Menu/CClear.h"

#include "Components/Button.h"

#include "Global.h"

bool UCClear::Initialize()
{
	bool bSuccess = Super::Initialize();
	CheckFalseResult(bSuccess, false);

	CheckNullResult(QuitButton, false);
	ContinueButton->OnClicked.AddDynamic(this, &UCClear::ContinueButtonPressed);
	QuitButton->OnClicked.AddDynamic(this, &UCClear::QuitButtonPressed);

	return true;
}

void UCClear::ContinueButtonPressed()
{
	Detach();
}

void UCClear::QuitButtonPressed()
{
	Detach();

	UWorld* world = GetWorld();
	CheckNull(world);

	APlayerController* controller = world->GetFirstPlayerController();

	controller->ConsoleCommand("Quit");
}