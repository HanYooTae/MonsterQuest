#pragma once

#include "CoreMinimal.h"
#include "CEnemy/CEnemy.h"
#include "CEnemy_Boss.generated.h"

UCLASS()
class MONSTERQUEST_API ACEnemy_Boss : public ACEnemy
{
	GENERATED_BODY()
	
public:
	ACEnemy_Boss();

protected:
	virtual void BeginPlay() override;

protected:
	virtual void End_Dead() override;

private:
	void Boss_Dead();
};
