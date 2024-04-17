#include "ActorComponents/CStatusComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Global.h"

UCStatusComponent::UCStatusComponent() {}


void UCStatusComponent::BeginPlay()
{
	Super::BeginPlay();

	// 난이도 조정을 위해서 CurrentHealth값을 조정해볼까? ex) 워크래프트
	CurrentHealth = MaxHealth;
}

void UCStatusComponent::ChangeMovementSpeed(EWalkSpeedType InWalkType)
{
	UCharacterMovementComponent* movementComp = CHelpers::GetComponent<UCharacterMovementComponent>(GetOwner());
	CheckNull(movementComp);

	movementComp->MaxWalkSpeed = WalkSpeed[(int8)InWalkType];
}

void UCStatusComponent::DecreaseHealth(float InHealth)
{
	CurrentHealth -= InHealth;
	CurrentHealth = FMath::Clamp(CurrentHealth, 0.f, MaxHealth);
}

void UCStatusComponent::IncreaseHealth(float InHealth)
{
	CurrentHealth += InHealth;
	CurrentHealth = FMath::Clamp(CurrentHealth, 0.f, MaxHealth);
}