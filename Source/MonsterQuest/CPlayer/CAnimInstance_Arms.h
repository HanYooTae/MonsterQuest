#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ActorComponents/CActionComponent.h"
#include "CAnimInstance_Arms.generated.h"

UCLASS()
class MONSTERQUEST_API UCAnimInstance_Arms : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	UFUNCTION()
		void OnWeaponTypeChanged(EActionType InPrevType, EActionType InNewType);

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Guns")
		EActionType ActionType = EActionType::Max;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Guns")
		FTransform LeftHandTransform;

private:
	class ACPlayer* Owner;
	class UCActionComponent* ActionComp;
};
