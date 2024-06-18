#pragma once

#include "CoreMinimal.h"
#include "Actions/DoActions/CDoAction.h"
#include "CDoAction_Fire.generated.h"

UCLASS()
class MONSTERQUEST_API ACDoAction_Fire : public ACDoAction
{
	GENERATED_BODY()
	
public:
	ACDoAction_Fire();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION() virtual void DoAction() override;
	UFUNCTION() virtual void Begin_DoAction() override;
	UFUNCTION() virtual void End_DoAction() override;
	UFUNCTION() virtual void Load_Magazine() override;


	UFUNCTION() void OnBulletBeginOverlap(FHitResult hitResult);

public:
	class ACBullet* Bullet;
	class ACWeapon* Weapon;
	class ACReload* Reload;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Fire")
		TSubclassOf<class ACBullet> BulletClass;

	UPROPERTY(EditDefaultsOnly, Category = "Fire")
		float AutoFireInterval = 0.15f;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Recoil")
		float RecoilAngle = 0.75f;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Trace")
		float HitDistance = 3000;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Fire")
		FName MuzzleBoneName;

	UPROPERTY(EditDefaultsOnly, Category = "Fire")
		class USoundWave* FireSound;

private:
	float CurrSpreadRadius;
	float LastAddSpreadTime;

private:
	FTimerHandle AutoFireHandle;

protected:
	FReloadData ReloadData;
};
