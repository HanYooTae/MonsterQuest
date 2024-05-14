#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActionDatas/CActionData.h"
#include "ActorComponents/CActionComponent.h"
#include "CEquipment.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBeginSwordEquipSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBeginEquipSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUnequipSignature);

UCLASS()
class MONSTERQUEST_API ACEquipment : public AActor
{
	GENERATED_BODY()
	
public:	
	ACEquipment();

protected:
	virtual void BeginPlay() override;

public:
	FORCEINLINE void SetData(const FEquipmentData& InData) { EquipmentData = InData; }
	FORCEINLINE const bool* IsEquippedThis() { return &bEquippedThis; }

public:
	// Play Draw Montage
	UFUNCTION(BlueprintNativeEvent)
		void Equip();
	void Equip_Implementation();

	// Attach to hand socket
	UFUNCTION(BlueprintNativeEvent)
		void Begin_Sword_Equip();
	void Begin_Sword_Equip_Implementation();

	UFUNCTION(BlueprintNativeEvent)
		void Begin_Equip();
	void Begin_Equip_Implementation();

	// Set State Idle
	UFUNCTION(BlueprintNativeEvent)
		void End_Equip();
	void End_Equip_Implementation();

	// ���⸦ ������ orient�� ���ִ� ����
	UFUNCTION(BlueprintNativeEvent)
		void Unequip();
	void Unequip_Implementation();

protected:
	UPROPERTY(BlueprintReadOnly)
		class ACharacter* OwnerCharacter;
	UPROPERTY(BlueprintReadOnly)
		class UCStateComponent* StateComp;
	UPROPERTY(BlueprintReadOnly)
		class UCStatusComponent* StatusComp;
	UPROPERTY(EditAnywhere)
		class ACPlayer* Player;

public:
	UPROPERTY(BlueprintAssignable)
		FBeginSwordEquipSignature OnBeginSwordEquip;

	UPROPERTY(BlueprintAssignable)
		FBeginEquipSignature OnBeginEquip;

	UPROPERTY(BlueprintAssignable)
		FUnequipSignature OnUnequip;

private:
	FEquipmentData EquipmentData;

	bool bEquippedThis;		// ���Ⱑ ������ �Ǿ��ִ��� �ƴ��� �Ǵ��ϴ� ����
};
