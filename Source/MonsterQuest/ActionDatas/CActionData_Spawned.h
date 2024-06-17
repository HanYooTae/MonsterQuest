#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MatineeCameraShake.h"
#include "CActionData_Spawned.generated.h"

USTRUCT(BlueprintType)
struct FEquipmentData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		class UAnimMontage* AnimMontage;

	UPROPERTY(EditAnywhere)
		float PlayRate = 1.f;

	UPROPERTY(EditAnywhere)
		FName StartSection;

	UPROPERTY(EditAnywhere)
		bool bCanMove = true;

	UPROPERTY(EditAnywhere)
		bool bPawnControl = true;
};

USTRUCT(BlueprintType)
struct FDoActionData : public FEquipmentData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		float Power = 1.f;

	UPROPERTY(EditAnywhere)
		float HitStop;

	UPROPERTY(EditAnywhere)
		class UParticleSystem* Effect;

	UPROPERTY(EditAnywhere)
		FTransform EffectTransform;

	UPROPERTY(EditAnywhere)
		TSubclassOf<UMatineeCameraShake> ShakeClass;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ACBullet> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, Category = "Magazine")
		uint8 MaxMagazineCount = 30;
};

USTRUCT(BlueprintType)
struct FReloadData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ACMagazine> MagazineClass;

	UPROPERTY(EditAnywhere)
		class UAnimMontage* ReloadMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Magazine")
		FName MagazineBoneName;

	UPROPERTY(EditDefaultsOnly, Category = "Magazine")
		FName MagazineAttachSocketName;

	UPROPERTY(EditAnywhere)
		float PlayRate = 1.f;

	UPROPERTY(EditAnywhere)
		FName StartSection;

	UPROPERTY(EditAnywhere)
		bool bCanMove = true;

	UPROPERTY(EditAnywhere)
		bool bPawnControl = true;
};

UCLASS()
class MONSTERQUEST_API UCActionData_Spawned : public UObject
{
	GENERATED_BODY()
	
public:		// UCActionData와의 접근성을 용이하게 하기 위하여 friend class로 지정
	friend class UCActionData;

public:
	FORCEINLINE class ACWeapon* GetWeapon() { return Weapon; }
	FORCEINLINE class ACEquipment* GetEquipment() { return Equipment; }
	FORCEINLINE class ACDoAction* GetDoAction() { return DoAction; }
	FORCEINLINE class ACReload* GetReload() { return Reload; }

private:
	class ACWeapon* Weapon;
	class ACEquipment* Equipment;
	class ACDoAction* DoAction;
	class ACReload* Reload;
};
