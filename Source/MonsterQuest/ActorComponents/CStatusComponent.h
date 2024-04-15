#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CStatusComponent.generated.h"

UENUM(BlueprintType)
enum class EWalkSpeedType : uint8
{
	Sneak, Walk, Run, Max
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MONSTERQUEST_API UCStatusComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCStatusComponent();

protected:
	virtual void BeginPlay() override;

public:		// Change Movement Speed
	FORCEINLINE float GetSneakSpeed() { return WalkSpeed[(int)EWalkSpeedType::Sneak]; }
	FORCEINLINE float GetWalkSpeed() { return WalkSpeed[(int)EWalkSpeedType::Walk]; }
	FORCEINLINE float GetRunSpeed() { return WalkSpeed[(int)EWalkSpeedType::Run]; }

	UFUNCTION()
		void ChangeMovementSpeed(EWalkSpeedType InWalkType);

public:		// Change Movement Status
	FORCEINLINE bool IsCanMove() { return bCanMove; }
	
	FORCEINLINE bool SetMove() { return bCanMove = true; }
	FORCEINLINE bool SetStop() { return bCanMove = false; }

public:		// Change HealthAmount
	UFUNCTION()
		void DecreaseHealth(float InHealth);

	UFUNCTION()
		void IncreaseHealth(float InHealth);

public:		// Get Health Status
		FORCEINLINE float GetMaxHealth() { return MaxHealth; }
		FORCEINLINE float GetCurrentHealth() { return CurrentHealth; }

		FORCEINLINE bool IsDead() { return CurrentHealth <= 0; }

private:
	UPROPERTY(EditDefaultsOnly, Category = "Speed")
		TArray<float> WalkSpeed{ 200.f, 400.f, 600.f };

	UPROPERTY(EditDefaultsOnly, Category = "Health")
		float MaxHealth = 100.f;

private:
	bool bCanMove = true;
	float CurrentHealth;
};
