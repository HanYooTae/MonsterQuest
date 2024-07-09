#include "CPlayer/CAnimInstance_Arms.h"
#include "CPlayer/CPlayer.h"

#include "GameFramework/Character.h"

#include <Global.h>

void UCAnimInstance_Arms::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	Player = Cast<ACPlayer>(TryGetPawnOwner());
	CheckNull(Player);

	ActionComp = CHelpers::GetComponent<UCActionComponent>(Player);
	if (!!ActionComp)
		ActionComp->OnActionTypeChanged.AddDynamic(this, &UCAnimInstance_Arms::OnActionTypeChanged);
}

void UCAnimInstance_Arms::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	CheckNull(Player);

	LeftHandTransform = ActionComp->GetArmsLeftHandTransform();
}

void UCAnimInstance_Arms::OnActionTypeChanged(EActionType InNewType)
{
	ActionType = InNewType;
}