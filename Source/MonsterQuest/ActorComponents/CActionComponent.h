#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CActionComponent.generated.h"

UENUM(BlueprintType)
enum class EActionType : uint8
{
	Unarmed, Sword, Pistol, Rifle, Sniper, Max
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActionTypeChangedSignature, EActionType, InNewType);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MONSTERQUEST_API UCActionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCActionComponent();

protected:
	virtual void BeginPlay() override;

public:		// Get Action
	UFUNCTION(BlueprintPure)
		class UCActionData_Spawned* GetCurrentData() { return Datas[(int32)Type]; }

	UFUNCTION(BlueprintPure)
		class UCActionData* GetCurrentDataAsset() { return DataAssets[(int32)Type]; }

public:		// bool Type
	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsUnarmedMode() { return Type == EActionType::Unarmed; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsSwordMode() { return Type == EActionType::Sword; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsPistolMode() { return Type == EActionType::Pistol; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsRifleMode() { return Type == EActionType::Rifle; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsSniperMode() { return Type == EActionType::Sniper; }

public:		// Set Action NetMulticast
	UFUNCTION(BlueprintCallable)
		void SetUnarmedMode();

	UFUNCTION(BlueprintCallable)
		void SetSwordMode();

	UFUNCTION(BlueprintCallable)
		void SetPistolMode();

	UFUNCTION(BlueprintCallable)
		void SetRifleMode();

	UFUNCTION(BlueprintCallable)
		void SetSniperMode();

private:
	UFUNCTION()
		void SetMode(EActionType InNewType);		// 무기를 들고 있을 때 같은 무기를 호출하면 Unarmed로 회귀시켜주는 함수

	UFUNCTION()
		void ChangeType(EActionType InNewType);

public:		// Get Assets
	UFUNCTION()
		void DoAction();

	UFUNCTION()
		void DoAim(bool InPressed);


	UFUNCTION()
		void OffAllCollisions();		// 죽었을 때 무기 충돌체 Off

	UFUNCTION()
		void End_Dead();

public:
	UPROPERTY(BlueprintAssignable)
		FActionTypeChangedSignature OnActionTypeChanged;

public:
	UPROPERTY(EditDefaultsOnly)
		class UCActionData* DataAssets[(int32)EActionType::Max];

private:
	EActionType Type;
	class UCActionData_Spawned* Datas[(int32)EActionType::Max];
};
