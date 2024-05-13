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
	UFUNCTION()
		virtual void DoAction() override;
	virtual void Begin_DoAction() override;
	virtual void End_DoAction() override;

private:
	class UCActionComponent* ActionComp;

private:
	class ACBullet* Bullet;
};
