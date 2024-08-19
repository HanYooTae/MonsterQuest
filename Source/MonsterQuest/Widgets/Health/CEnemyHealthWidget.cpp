#include "Widgets/Health/CEnemyHealthWidget.h"
#include "Components/ProgressBar.h"

void UCEnemyHealthWidget::UpdateHealth(float InCurrentHealth, float InMaxHealth)
{
	HealthBar->SetPercent(InCurrentHealth / InMaxHealth);
}