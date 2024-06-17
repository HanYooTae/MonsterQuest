#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CMagazine.generated.h"

UCLASS()
class MONSTERQUEST_API ACMagazine : public AActor
{
	GENERATED_BODY()
	
public:	
	ACMagazine();

protected:
	virtual void BeginPlay() override;

public:
	void Eject();

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Root;

	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Mesh;

private:
	bool bEject;
};
