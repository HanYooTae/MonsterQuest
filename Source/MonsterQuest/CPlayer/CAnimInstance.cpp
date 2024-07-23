#include "CPlayer/CAnimInstance.h"
#include "CPlayer/CPlayer.h"
#include "ActorComponents/CActionComponent.h"
#include "Actions/DoActions/CDoAction.h"
#include "Actions/Aim/CAim_Rifle.h"

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

	ActionComp = CHelpers::GetComponent<UCActionComponent>(OwnerCharacter);
	CheckNull(ActionComp);

	ActionComp->OnActionTypeChanged.AddDynamic(this, &UCAnimInstance::OnActionTypeChanged);
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

	ActionComp = CHelpers::GetComponent<UCActionComponent>(OwnerCharacter);
	CheckNull(ActionComp);

	bAiming = ActionComp->IsAim();
}

void UCAnimInstance::OnActionTypeChanged(EActionType InNewType)
{
	ActionType = InNewType;
}