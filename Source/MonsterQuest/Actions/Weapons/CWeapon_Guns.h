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
	void Begin_Fire();
	void End_Fire();

	UFUNCTION()
		void OnFiring();

protected:
	class UCUserWidget_CrossHair* CrossHair;

	UPROPERTY(EditDefaultsOnly, Category = "HUD")
		TSubclassOf<class UCUserWidget_CrossHair> CrossHairClass;

private:
	bool bFiring;
	bool bAutoFire = true;

private:
	FTimerHandle AutoFireHandle;
};
