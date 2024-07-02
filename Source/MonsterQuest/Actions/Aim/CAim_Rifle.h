#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/TimelineComponent.h"
#include "CAim_Rifle.generated.h"

UCLASS()
class MONSTERQUEST_API UCAim_Rifle : public UObject
{
	GENERATED_BODY()
	
public:
	UCAim_Rifle();

	void BeginPlay(class ACharacter* InOwnerCharacter);
	void Tick(float DeltaTime);

	UFUNCTION() void On();
	UFUNCTION() void Off();

public:
	FORCEINLINE bool IsAvailable() { return SpringArm != nullptr && Camera != nullptr; }
	FORCEINLINE bool IsZooming() { return bZooming; }

private:
	UFUNCTION()
		void Zooming(float Output);

public:
	FOnTimelineFloat OnTimeline;

private:
	class ACharacter* OwnerCharacter;
	class USpringArmComponent* SpringArm;
	class UCameraComponent* Camera;

	bool bZooming;

	class UCurveFloat* Curve;
	FTimeline Timeline;
};