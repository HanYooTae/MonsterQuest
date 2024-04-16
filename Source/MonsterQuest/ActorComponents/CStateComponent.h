#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CStateComponent.generated.h"

UENUM(BlueprintType)
enum class EStateType : uint8
{
	Idle, Equip, Action, Hitted, Dead, Max
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FStateTypeChangedSignature, EStateType, InPrevType, EStateType, InNewType);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MONSTERQUEST_API UCStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCStateComponent();

public:		// Get StateType
	bool IsIdleMode() { return Type == EStateType::Idle; }
	bool IsEquipMode() { return Type == EStateType::Equip; }
	bool IsActionMode() { return Type == EStateType::Action; }
	bool IsHittedMode() { return Type == EStateType::Hitted; }
	bool IsDeadMode() { return Type == EStateType::Dead; }

public:		// Set StateType
	UFUNCTION()
		void SetIdleMode();
	UFUNCTION()
		void SetEquipMode();
	UFUNCTION()
		void SetActionMode();
	UFUNCTION()
		void SetHittedMode();
	UFUNCTION()
		void SetDeadMode();

	UFUNCTION()
		void ChangeType(EStateType InNewType);

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintAssignable)
		FStateTypeChangedSignature OnStateTypeChanged;

private:
	EStateType Type;
};
