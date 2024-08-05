#include "ActionDatas/CActionData.h"

#include "Actions/Weapons/CWeapon.h"
#include "Actions/Equipment/CEquipment.h"
#include "Actions/DoActions/CDoAction.h"
#include "Actions/Reload/CReload.h"
#include "ItemDatas/CItemData.h"
#include "ItemDatas/CItemStruct.h"

#include "GameFramework/Character.h"

#include "Global.h"

void UCActionData::BeginPlay(class ACharacter* InOwnerCharacter, UCActionData_Spawned** OutSpawned)
{
	FTransform transform;

	Weapon = nullptr;
	if (!!WeaponClass)
	{
		Weapon = InOwnerCharacter->GetWorld()->SpawnActorDeferred<ACWeapon>(WeaponClass, transform, InOwnerCharacter);

		Weapon->SetActorLabel(GetCustomLabel(InOwnerCharacter, "Weapon"));

		UGameplayStatics::FinishSpawningActor(Weapon, transform);
	}

	if (!!ItemData)
	{
		Weapon = InOwnerCharacter->GetWorld()->SpawnActorDeferred<ACWeapon>(ItemData->Item.WeaponClass, transform, InOwnerCharacter);

		Weapon->SetActorLabel(GetCustomLabel(InOwnerCharacter, "ItemWeapon"));

		UGameplayStatics::FinishSpawningActor(Weapon, transform);
	}

	Equipment = nullptr;
	if (!!EquipmentClass)
	{
		Equipment = InOwnerCharacter->GetWorld()->SpawnActorDeferred<ACEquipment>(EquipmentClass, transform, InOwnerCharacter);

		Equipment->SetData(EquipmentData);
		Equipment->SetActorLabel(GetCustomLabel(InOwnerCharacter, "Equipment"));

		UGameplayStatics::FinishSpawningActor(Equipment, transform);

		if (!!Weapon)
		{
			Equipment->OnBeginSwordEquip.AddDynamic(Weapon, &ACWeapon::OnSwordEquip);
			Equipment->OnBeginEquip.AddDynamic(Weapon, &ACWeapon::OnEquip);
			Equipment->OnUnequip.AddDynamic(Weapon, &ACWeapon::OnUnequip);
		}
	}

	Reload = nullptr;
	if (!!ReloadClass)
	{
		Reload = InOwnerCharacter->GetWorld()->SpawnActorDeferred<ACReload>(ReloadClass, transform, InOwnerCharacter);

		Reload->SetData(ReloadData);
		Reload->SetActorLabel(GetCustomLabel(InOwnerCharacter, "Reload"));

		UGameplayStatics::FinishSpawningActor(Reload, transform);
	}

	DoAction = nullptr;
	if (!!DoActionClass)
	{
		DoAction = InOwnerCharacter->GetWorld()->SpawnActorDeferred<ACDoAction>(DoActionClass, transform, InOwnerCharacter);

		DoAction->SetDatas(DoActionDatas);
		DoAction->SetActorLabel(GetCustomLabel(InOwnerCharacter, "DoAction"));

		UGameplayStatics::FinishSpawningActor(DoAction, transform);

		if (!!Weapon)
		{
			Weapon->OnBeginOverlap.AddDynamic(DoAction, &ACDoAction::OnBeginOverlap);
			Weapon->OnEndOverlap.AddDynamic(DoAction, &ACDoAction::OnEndOverlap);
		}
	}
	
	(*OutSpawned) = NewObject<UCActionData_Spawned>();
	(*OutSpawned)->Weapon = Weapon;
	(*OutSpawned)->Equipment = Equipment;
	(*OutSpawned)->DoAction = DoAction;
	(*OutSpawned)->Reload = Reload;
}

FString UCActionData::GetCustomLabel(ACharacter* InOwnerCharacter, FString InMiddleName)
{
	FString name;
	name.Append(InOwnerCharacter->GetActorLabel());
	name.Append("_");
	name.Append(InMiddleName);
	name.Append("_");

	name.Append(GetName().Replace(L"DA_", L""));

	return name;
}
