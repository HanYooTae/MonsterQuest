#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActorComponents/CStateComponent.h"
#include "Engine/DataTable.h"
#include "CMontagesComponent.generated.h"

USTRUCT(BlueprintType)
struct FMontageData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
		EStateType Type;
	
	UPROPERTY(EditDefaultsOnly)
		class UAnimMontage* AnimMontage;

	UPROPERTY(EditDefaultsOnly)
		float PlayRate = 1.f;

	UPROPERTY(EditDefaultsOnly)
		FName StateSection;

	UPROPERTY(EditDefaultsOnly)
		bool bCanMove;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MONSTERQUEST_API UCMontagesComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCMontagesComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION()
		void PlayHitted();
	UFUNCTION()
		void PlayDead();

private:
	UFUNCTION()
		void PlayMontage(EStateType InStateType);

private:
	UPROPERTY(EditDefaultsOnly, Category = "DataTable")
		UDataTable* DataTable;

private:
	FMontageData* Datas[(int8)EStateType::Max];
};
