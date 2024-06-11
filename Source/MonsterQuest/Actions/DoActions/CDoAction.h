#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActionDatas/CActionData.h"
#include "CDoAction.generated.h"

UCLASS()
class MONSTERQUEST_API ACDoAction : public AActor
{
	GENERATED_BODY()
	
public:	
	ACDoAction();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	FORCEINLINE bool IsAutoFire() { return bAutoFire; }
	FORCEINLINE void ToggleAutoFire() { bAutoFire = !bAutoFire; }
	FORCEINLINE void SetDatas(TArray<FDoActionData> InDatas) { Datas = InDatas; }

public:
	virtual void DoAction() {};
	virtual void Begin_DoAction() {};
	virtual void End_DoAction() {};

public:		// 원거리 무기 전용 함수
	virtual void OnAim() {};
	virtual void OffAim() {};

public:
	virtual void Reload() {};
	virtual void Eject_Magazine() {};
	virtual void Spawn_Magazine() {};
	virtual void Load_Magazine() {};
	virtual void End_Reload() {};

public:
	UFUNCTION()
		virtual void OnBeginOverlap(class ACharacter* InAttacker, class AActor* InCauser, class ACharacter* InOtherCharacter) {};

	UFUNCTION()
		virtual void OnEndOverlap(class ACharacter* InAttacker, class AActor* InCauser, class ACharacter* InOtherCharacter) {};

protected:
	UPROPERTY(BlueprintReadOnly)
		class ACharacter* OwnerCharacter;

	UPROPERTY(BlueprintReadOnly)
		class UCStatusComponent* StatusComp;

	UPROPERTY(BlueprintReadOnly)
		class UCStateComponent* StateComp;

	UPROPERTY(BlueprintReadOnly)
		class UCActionComponent* ActionComp;

protected:
	TArray<FDoActionData> Datas;

protected:
	bool bAutoFire = true;

public:	// Sword공격 시, Player의 EndAttack을 return해주는 flag
	bool bCanEndAttack = true;
};