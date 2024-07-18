#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CEnemy.generated.h"

UCLASS()
class MONSTERQUEST_API ACEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	ACEnemy();

protected:
	virtual void BeginPlay() override;

public:
	FORCEINLINE class UBehaviorTree* GetBehaviorTree() { return BehaviorTree; }

public:
	virtual float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintCallable)
		bool Getdead() { return dead; }
	bool dead = false;

	UFUNCTION(BlueprintImplementableEvent)
		void Dissolve();

private:
	UFUNCTION()
		void Hitted();

	UFUNCTION()
		void Dead();

	UFUNCTION()
		void End_Dead();

protected: //Actor Component
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
		class UCEnemyActionComponent* EnemyAction;

	UPROPERTY(VisibleDefaultsOnly)
		class UCMontagesComponent* Montages;

	UPROPERTY(VisibleDefaultsOnly)
		class UCStateComponent* State;

	UPROPERTY(VisibleDefaultsOnly)
		class UCStatusComponent* Status;

private:
	float DamageValue;

private:
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		class UBehaviorTree* BehaviorTree;
};
