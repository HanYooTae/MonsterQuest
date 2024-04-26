#pragma once

#include "CoreMinimal.h"
#include "Actions/DoActions/CDoAction.h"
#include "CDoAction_Sword.generated.h"

UCLASS()
class MONSTERQUEST_API ACDoAction_Sword : public ACDoAction
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
		virtual void DoAction() override;
	UFUNCTION()
		virtual void Begin_DoAction() override;
	UFUNCTION()
		virtual void End_DoAction() override;

public:
public:
	virtual void OnBeginOverlap(class ACharacter* InAttacker, class AActor* InCauser, class ACharacter* InOtherCharacter) override;

	virtual void OnEndOverlap(class ACharacter* InAttacker, class AActor* InCauser, class ACharacter* InOtherCharacter) override;

	FORCEINLINE void EnableCombo() { bCanCombo = true; }
	FORCEINLINE void DisableCombo() { bCanCombo = false; }
	FORCEINLINE void ClearHittedCharacters() { HittedCharacters.Empty(); }

private:
	UFUNCTION()
		void RestoreTimeDilation();

private:
	int32 ComboCount;
	bool bCanCombo;
	bool bSucceed;

	TArray<class ACharacter*> HittedCharacters;
};
