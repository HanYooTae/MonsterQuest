#include "Widgets/Health/CPlayerHealthWidget.h"

#include "CPlayer/CPlayer.h"
#include "ActorComponents/CStatusComponent.h"

#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"

#include "Global.h"

void UCPlayerHealthWidget::NativeConstruct()
{
	ACPlayer* player = Cast<ACPlayer>(GetOwningPlayer()->GetCharacter());
	CheckNull(player);

	StatusComp = CHelpers::GetComponent<UCStatusComponent>(player);
	CheckNull(StatusComp);

	CheckNull(CurrentHealthText);
	CurrentHealthStr = FString::FromInt((int32)StatusComp->GetCurrentHealth());
	CurrentHealthText->SetText(FText::FromString(CurrentHealthStr));

	CheckNull(MaxHealthText);
	MaxHealthStr = FString::FromInt((int32)StatusComp->GetMaxHealth());
	MaxHealthText->SetText(FText::FromString(MaxHealthStr));

	HealthBar->SetPercent(StatusComp->GetCurrentHealth() / StatusComp->GetMaxHealth());

	Super::NativeConstruct();
}

void UCPlayerHealthWidget::UpdateHealth()
{
	CheckNull(StatusComp);
	CheckNull(CurrentHealthText);
	CurrentHealthStr = FString::FromInt((int32)StatusComp->GetCurrentHealth());
	CurrentHealthText->SetText(FText::FromString(CurrentHealthStr));

	CheckNull(MaxHealthText);
	MaxHealthStr = FString::FromInt((int32)StatusComp->GetMaxHealth());
	MaxHealthText->SetText(FText::FromString(MaxHealthStr));

	HealthBar->SetPercent(StatusComp->GetCurrentHealth() / StatusComp->GetMaxHealth());
}