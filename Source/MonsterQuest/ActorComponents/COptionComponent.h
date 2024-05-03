#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "COptionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MONSTERQUEST_API UCOptionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCOptionComponent();

protected:
	virtual void BeginPlay() override;

public:
	FORCEINLINE float GetZoomSpeed() { return ZoomSpeed; }

	FORCEINLINE float GetZoomMin() { return ZoomRange.X; }
	FORCEINLINE float GetZoomMax() { return ZoomRange.Y; }

private:
	UPROPERTY(EditAnywhere, Category = "Mouse")
		float ZoomSpeed = 1000.f;

	UPROPERTY(EditAnywhere, Category = "Mouse")
		FVector2D ZoomRange = FVector2D(100, 500);
};