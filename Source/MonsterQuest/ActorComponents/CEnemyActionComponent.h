#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CEnemyActionComponent.generated.h"

UENUM(BlueprintType)
enum class EEnemyActionType : uint8
{
	Unarmed, Sword, Max
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEnemyActionTypeChangedSignature, EEnemyActionType, InNewType);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MONSTERQUEST_API UCEnemyActionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCEnemyActionComponent();

protected:
	virtual void BeginPlay() override;

public:		// Get Action
	UFUNCTION(BlueprintPure)
		class UCActionData_Spawned* GetCurrentData() { return Datas[(int32)Type]; }

	UFUNCTION(BlueprintPure)
		class UCActionData* GetCurrentDataAsset() { return DataAssets[(int32)Type]; }

public:		// bool Type
	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsUnarmedMode() { return Type == EEnemyActionType::Unarmed; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsSwordMode() { return Type == EEnemyActionType::Sword; }

public:		// Set Action NetMulticast
	UFUNCTION(BlueprintCallable)
		void SetUnarmedMode();

	UFUNCTION(BlueprintCallable)
		void SetSwordMode();

private:
	UFUNCTION()
		void SetMode(EEnemyActionType InNewType);		// 무기를 들고 있을 때 같은 무기를 호출하면 Unarmed로 회귀시켜주는 함수

	UFUNCTION()
		void ChangeType(EEnemyActionType InNewType);

public:		// Get Assets
	UFUNCTION()
		void DoAction();

	UFUNCTION()
		void OffAllCollisions();		// 죽었을 때 무기 충돌체 Off

	UFUNCTION()
		void End_Dead();

public:
	UPROPERTY(BlueprintAssignable)
		FEnemyActionTypeChangedSignature OnEnemyActionTypeChanged;

public:
	UPROPERTY(EditDefaultsOnly)
		class UCActionData* DataAssets[(int32)EEnemyActionType::Max];

public:
	EEnemyActionType Type;
	class UCActionData_Spawned* Datas[(int32)EEnemyActionType::Max];
};
