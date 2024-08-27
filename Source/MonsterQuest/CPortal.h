#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPortal.generated.h"

UCLASS()
class MONSTERQUEST_API ACPortal : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPortal();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
		void OnInteract();

private:
	TSubclassOf<class UCInteract> InteractWidgetClass;
	class UCInteract* InteractWidget;

private:
	UPROPERTY(VisibleDefaultsOnly)
		class UBoxComponent* Box;

	UPROPERTY(VisibleDefaultsOnly)
		class UParticleSystemComponent* ParticleComponent;

	UPROPERTY(EditAnywhere)
		FName TransferLevelName;

public:
	UPROPERTY(EditDefaultsOnly, Category = "ItemData")
		class UCItemData* ItemData;
};