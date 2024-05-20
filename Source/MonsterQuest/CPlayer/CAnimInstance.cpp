#include "CPlayer/CAnimInstance.h"

#include "Global.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CAnimInstance.h"

UCAnimInstance::UCAnimInstance()
{
}

void UCAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	OwnerCharacter = Cast<ACharacter>(TryGetPawnOwner());

	UCActionComponent* actionComp = CHelpers::GetComponent<UCActionComponent>(OwnerCharacter);
	CheckNull(actionComp);

	actionComp->OnActionTypeChanged.AddDynamic(this, &UCAnimInstance::OnActionTypeChanged);
}

void UCAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	OwnerCharacter = Cast<ACharacter>(TryGetPawnOwner());
	CheckNull(OwnerCharacter);

	Speed = OwnerCharacter->GetVelocity().Size2D();
	Direction = CalculateDirection(OwnerCharacter->GetVelocity(), OwnerCharacter->GetControlRotation());
	Pitch = OwnerCharacter->GetBaseAimRotation().Pitch;
	Falling = OwnerCharacter->GetCharacterMovement()->IsFalling();
}

void UCAnimInstance::OnActionTypeChanged(EActionType InNewType)
{
	ActionType = InNewType;
}