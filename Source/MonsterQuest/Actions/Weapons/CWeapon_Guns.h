#pragma once

#include "CoreMinimal.h"
#include "Actions/Weapons/CWeapon.h"
#include "CWeapon_Guns.generated.h"

UCLASS()
class MONSTERQUEST_API ACWeapon_Guns : public ACWeapon
{
	GENERATED_BODY()
	
public:
	ACWeapon_Guns();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;


public:
	FORCEINLINE bool IsFiring() { return bFiring; }
	FORCEINLINE bool IsAutoFire() { return bAutoFire; }

	bool CanFire();
	void Begin_Fire() override;
	void End_Fire();

	UFUNCTION()
		void OnFiring();

private:
	bool bFiring;
	bool bAutoFire = true;

private:
	FTimerHandle AutoFireHandle;

protected:
	class UCUserWidget_CrossHair* CrossHair;

	UPROPERTY(EditDefaultsOnly, Category = "HUD")
		TSubclassOf<class UCUserWidget_CrossHair> CrossHairClass;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Fire")
		FName EjectBoneName;

	UPROPERTY(EditDefaultsOnly, Category = "Fire")
		class UParticleSystem* EjectParticle;

	UPROPERTY(EditDefaultsOnly, Category = "Fire")
		FName MuzzleBoneName;

	UPROPERTY(EditDefaultsOnly, Category = "Fire")
		class UParticleSystem* FlashParticle;

	UPROPERTY(EditDefaultsOnly, Category = "Fire")
		class USoundWave* FireSound;

	UPROPERTY(EditDefaultsOnly, Category = "Fire")
		TSubclassOf<class ACBullet> BulletClass;

	UPROPERTY(EditDefaultsOnly, Category = "Fire")
		TSubclassOf<class UMatineeCameraShake> CameraShakeClass;

	UPROPERTY(EditDefaultsOnly, Category = "Fire")
		float AutoFireInterval = 0.15f;
};
