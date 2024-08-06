#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CDropItem.generated.h"

UCLASS()
class MONSTERQUEST_API ACDropItem : public AActor
{
	GENERATED_BODY()
	
public:	
	ACDropItem();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
		void OnInteract();

public:
	UPROPERTY(EditDefaultsOnly, Category = "ItemData")
		class UCItemData* ItemData;

protected:
	UPROPERTY(VisibleAnywhere)
		class USkeletalMeshComponent* SkeletalMesh;

	UPROPERTY(VisibleAnywhere)
		class USphereComponent* Sphere;

private:
	TSubclassOf<class UCInteract> InteractWidgetClass;
	class UCInteract* InteractWidget;
};
