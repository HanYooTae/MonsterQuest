#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActionDatas/CActionData.h"
#include "CReload.generated.h"

UCLASS()
class MONSTERQUEST_API ACReload : public AActor
{
	GENERATED_BODY()
	
public:	
	ACReload();

protected:
	virtual void BeginPlay() override;

public:
	FORCEINLINE void SetData(const FReloadData& InData) { ReloadData = InData; }

public:
	void Reload();
	void Eject_Magazine();
	void End_Reload();

public:
	class ACWeapon* Weapon;
	class ACDoAction* DoAction;

protected:
	UPROPERTY(BlueprintReadOnly)
		class ACharacter* OwnerCharacter;
	UPROPERTY(BlueprintReadOnly)
		class UCStateComponent* StateComp;
	UPROPERTY(BlueprintReadOnly)
		class UCStatusComponent* StatusComp;
	UPROPERTY(BlueprintReadOnly)
		class UCActionComponent* ActionComp;

protected:
	FReloadData ReloadData;
	class ACMagazine* Magazine;

public:
	bool bReload;	// CanReload
};