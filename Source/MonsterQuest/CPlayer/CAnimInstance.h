#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ActorComponents/CActionComponent.h"
#include "CAnimInstance.generated.h"

UCLASS()
class MONSTERQUEST_API UCAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UCAnimInstance();

public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	UFUNCTION()
		void OnActionTypeChanged(EActionType InNewType);

protected:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Animation")
		float Speed;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Animation")
		float Direction;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Animation")
		float Pitch;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Animation")
		bool Falling;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Animation")
		EActionType ActionType;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Guns")
		bool bFiring;

private:
	class ACharacter* OwnerCharacter;
};
