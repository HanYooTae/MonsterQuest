#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CNpc.generated.h"

UCLASS()
class MONSTERQUEST_API ACNpc : public ACharacter
{
	GENERATED_BODY()

public:
	ACNpc();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void OnInteract();

private:	// Character Settings
	UPROPERTY(VisibleDefaultsOnly)
		class USphereComponent* Sphere;

private:	// Widgets
	TSubclassOf<class UUserWidget> InteractWidgetClass;
	class UCInteract* InteractWidget;

};
