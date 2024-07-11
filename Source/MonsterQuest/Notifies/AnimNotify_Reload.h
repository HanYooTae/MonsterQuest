#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_Reload.generated.h"

UENUM(BlueprintType)
enum class EMagazineActionType : uint8
{
	Eject, Load, End
};

UCLASS()
class MONSTERQUEST_API UAnimNotify_Reload : public UAnimNotify
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, Category = "Magazine")
		EMagazineActionType ActionType;

public:
	FString GetNotifyName_Implementation() const override;
	virtual void Notify(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation) override;
};
