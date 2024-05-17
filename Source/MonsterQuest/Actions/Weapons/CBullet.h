#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CBullet.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBulletBeginOverlapSignature, FHitResult, InHitResult);

UCLASS()
class MONSTERQUEST_API ACBullet : public AActor
{
	GENERATED_BODY()
	
public:	
	ACBullet();

private:
	UFUNCTION()
		void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


protected:
	virtual void BeginPlay() override;

public:
	void Shoot(const FVector& InDirection);

private:
	UPROPERTY(VisibleDefaultsOnly)
		class UCapsuleComponent* Capsule;

	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleDefaultsOnly)
		class UProjectileMovementComponent* Projectile;

public:
	UPROPERTY(BlueprintAssignable)
		FBulletBeginOverlapSignature OnBeginOverlap;
};