#include "ActorComponents/CStatusComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Global.h"

UCStatusComponent::UCStatusComponent() {}


void UCStatusComponent::BeginPlay()
{
	Super::BeginPlay();

	// ���̵� ������ ���ؼ� CurrentHealth���� �����غ���? ex) ��ũ����Ʈ
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