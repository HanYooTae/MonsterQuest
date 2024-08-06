// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GenericTeamAgentInterface.h"
#include "CPlayer.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCharacterBeginOverlapSignature);
DECLARE_DYNAMIC_DELEGATE(FInteractSignature);

UCLASS(config=Game)
class ACPlayer : public ACharacter, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	ACPlayer();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

protected:
	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);
	
protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	FORCEINLINE class UStaticMeshComponent* GetDotSight() const { return DotSight; }

public:
	class UCActionComponent* GetAction() { return Action; }

protected:
	void DrawSword();
	void DrawPistol();
	void DrawRifle();
	void DrawSniper();

protected:
	void NormalAttack();
	void EndAttack();
	void ToggleAutoFire();
	void ToggleReload();
	void OnAim();
	void OffAim();
	void Interact();

private:
	virtual float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION()
		void Hitted();

	UFUNCTION()
		void Dead();

	UFUNCTION()
		void End_Dead();

protected:
	void OnZoom(float InAxis);

public:
	virtual FGenericTeamId GetGenericTeamId() const override;

public:
	FCharacterBeginOverlapSignature OnCharacterBeginOverlap;
	FInteractSignature OnInteract;

public:
	FORCEINLINE class UStaticMeshComponent* GetBackpack() { return Backpack; }

public:
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;

private:    // Character Component
	UPROPERTY(VisibleDefaultsOnly)
		class UCStatusComponent* Status;

	UPROPERTY(VisibleDefaultsOnly)
		class UCStateComponent* State;

	UPROPERTY(VisibleDefaultsOnly)
		class UCMontagesComponent* Montages;

	UPROPERTY(VisibleDefaultsOnly)
		class UCActionComponent* Action;

	UPROPERTY(VisibleDefaultsOnly)
		class UCOptionComponent* Option;

	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Backpack;

protected:
	UPROPERTY(VisibleDefaultsOnly)
		class ACWeapon* Weapon;

public:
	UPROPERTY(EditDefaultsOnly, Category = "HUD")
		TSubclassOf<class UCUserWidget_CrossHair> CrossHairClass;

	UPROPERTY(EditDefaultsOnly, Category = "HUD")
		TSubclassOf<class UCUserWidget_Information> InformationClass;

	UPROPERTY(EditAnywhere, Category = "Weapon")
		TSubclassOf<class UCUserWidget_HUD> HUDClass;

public:
	class UCUserWidget_CrossHair* CrossHair;
	class UCUserWidget_Information* Information;
	class UCUserWidget_HUD* HUD;

private:
	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* DotSight;

private:
	UPROPERTY(EditDefaultsOnly)
		uint8 PlayerTeamID = 0;
	FGenericTeamId TeamGeneicID;

private:
	float DamageValue;
};

