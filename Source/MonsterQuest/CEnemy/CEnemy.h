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
	virtual float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintImplementableEvent)
		void Dissolve();

private:
	UFUNCTION()
		void Hitted();

	UFUNCTION()
		void Dead();

	UFUNCTION()
		void End_Dead();

public:
	FORCEINLINE class UBehaviorTree* GetBehaviorTree() { return BehaviorTree; }
	FORCEINLINE uint8 GetTeamID() { return TeamID; }

private: // Health Widget
	class UWidgetComponent* HealthWidget;

protected: //Actor Component
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
		class UCActionComponent* Action;

private:
	UPROPERTY(VisibleDefaultsOnly)
		class UCMontagesComponent* Montages;

	UPROPERTY(VisibleDefaultsOnly)
		class UCStateComponent* State;

	UPROPERTY(VisibleDefaultsOnly)
		class UCStatusComponent* Status;

private:
	UPROPERTY(EditAnywhere)
		float LaunchValue = 25.f;

private:
	class ACharacter* Attacker;
	class AActor* Causer;
	float DamageValue;

//private:
//	UPROPERTY(VisibleDefaultsOnly)
//		class UCPatrolComponent* Patrol;

private:
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		class UBehaviorTree* BehaviorTree;

	UPROPERTY(EditDefaultsOnly, Category = "Team")
		uint8 TeamID = 1;
};
