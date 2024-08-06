#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "CItemStruct.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Weapon,
	Consume,
	Max
};

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	Unarmed,
	Sword,
	Pistol,
	Rifle,
	Sniper,
	Max
};

USTRUCT(Atomic, BlueprintType)
struct FItemStruct : public FTableRowBase
{
	GENERATED_BODY()

public:
	// Item Name
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString Name = "NULL";

	// Item Description
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString Description;

	// Interaction Comment
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString Interact;

	// ItemType
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		EItemType ItemType;

	// WeaponType
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		EWeaponType WeaponType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TSubclassOf<class ACWeapon> WeaponClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TSubclassOf<class ACDropItem> CDropItemClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UTexture2D* Picture;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UTexture2D* WeaponIcon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UTexture2D* FirstSkillIcon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UTexture2D* SecondSkillIcon;
};

UCLASS()
class MONSTERQUEST_API ACItemStruct : public AActor
{
	GENERATED_BODY()
	
public:	
	ACItemStruct();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
