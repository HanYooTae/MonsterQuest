#include "Widgets/Menu/CLose.h"

#include "Components/Button.h"

#include "Global.h"

bool UCLose::Initialize()
{
	bool bSuccess = Super::Initialize();
	CheckFalseResult(bSuccess, false);

	CheckNullResult(QuitButton, false);
	QuitButton->OnClicked.AddDynamic(this, &UCLose::QuitButtonPressed);

	return true;
}

void UCLose::QuitButtonPressed()
{
	Detach();

	UWorld* world = GetWorld();
	CheckNull(world);

	APlayerController* controller = world->GetFirstPlayerController();

	controller->ConsoleCommand("Quit");
}