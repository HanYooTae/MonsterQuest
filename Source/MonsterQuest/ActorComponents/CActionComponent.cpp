#include "ActorComponents/CActionComponent.h"

#include "ActionDatas/CActionData_Spawned.h"
#include "ActionDatas/CActionData.h"
#include "Actions/Equipment/CEquipment.h"
#include "Actions/DoActions/CDoAction.h"
#include "Actions/DoActions/CDoAction_Fire.h"
#include "Actions/Reload/CReload.h"
#include "Actions/Weapons/CWeapon.h"
#include "Widgets/HUD/CUserWidget_HUD.h"

#include "GameFramework/Character.h"

#include "Global.h"

UCActionComponent::UCActionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	CHelpers::GetClass<UCUserWidget_HUD>(&HUDClass, "WidgetBlueprint'/Game/Widgets/HUD/WB_HUD.WB_HUD_C'");
}

void UCActionComponent::BeginPlay()
{
	Super::BeginPlay();

	ACharacter* ownerCharacter = Cast<ACharacter>(GetOwner());

	for (int32 i = 0; i < (int32)EActionType::Max; i++)
	{
		if (!!DataAssets[i])
			DataAssets[i]->BeginPlay(ownerCharacter, &Datas[i]);
	}

	if (!!HUDClass)
	{
		HUD = CreateWidget<UCUserWidget_HUD, APlayerController>(Cast<ACharacter>(GetOwner())->GetController<APlayerController>(), HUDClass);
		HUD->AddToViewport();
		HUD->SetVisibility(ESlateVisibility::Hidden);
	}
}

void UCActionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!!HUD)
	{
		ACDoAction* doAction = GetCurrentData()->GetDoAction();
		if (!!doAction)
		{
			doAction->IsAutoFire() ? HUD->OnAutoFire() : HUD->OffAutoFire();

			uint8 currMagazineCount = doAction->GetCurrMagazineCount();
			uint8 maxMagazineCount = 0;

			for (const auto& max : doAction->GetDatas())
			{
				maxMagazineCount = max.MaxMagazineCount;
				break;
			}

			HUD->UpdateMagazine(currMagazineCount, maxMagazineCount);
			HUD->UpdateWeaponName(Type);
		}
	}
}

void UCActionComponent::SetUnarmedMode()
{
	// 무기 해제
	if (!!Datas[(int32)Type] && !!Datas[(int32)Type]->GetEquipment())
		Datas[(int32)Type]->GetEquipment()->Unequip();

	ChangeType(EActionType::Unarmed);

	HUD->SetVisibility(ESlateVisibility::Hidden);
}

void UCActionComponent::SetSwordMode()
{
	SetMode(EActionType::Sword);
	HUD->SetVisibility(ESlateVisibility::Hidden);
}

void UCActionComponent::SetPistolMode()
{
	SetMode(EActionType::Pistol);
}

void UCActionComponent::SetRifleMode()
{
	SetMode(EActionType::Rifle);
}

void UCActionComponent::SetSniperMode()
{
	SetMode(EActionType::Sniper);
}

void UCActionComponent::SetMode(EActionType InNewType)
{
	// 같은 키를 2번 눌렀을 때
	if (Type == InNewType)
	{
		SetUnarmedMode();

		return;
	}

	// Unarmed가 아닌 Type을 장착하고 있었다면
	else if (IsUnarmedMode() == false)
	{
		// 이전 무기 장착 해제
		if (!!Datas[(int32)Type] && !!Datas[(int32)Type]->GetEquipment())
			Datas[(int32)Type]->GetEquipment()->Unequip();
	}
	// 새로운 무기 장착
	if (!!Datas[(int32)InNewType] && !!Datas[(int32)InNewType]->GetEquipment())
		Datas[(int32)InNewType]->GetEquipment()->Equip();

	ChangeType(InNewType);

	HUD->SetVisibility(ESlateVisibility::Visible);
}

void UCActionComponent::ChangeType(EActionType InNewType)
{
	Type = InNewType;

	if (OnActionTypeChanged.IsBound())
		OnActionTypeChanged.Broadcast(InNewType);
}

void UCActionComponent::DoAction()
{
	CheckTrue(IsUnarmedMode());

	if (!!GetCurrentData())
	{
		ACDoAction* doAction = GetCurrentData()->GetDoAction();
		if (!!doAction)
		{
			doAction->DoAction();
		}
	}
}

void UCActionComponent::DoAim(bool InPressed)
{
	CheckTrue(IsSwordMode());
	CheckTrue(IsPistolMode());

	if (!!GetCurrentData())
	{
		ACDoAction* doAction = GetCurrentData()->GetDoAction();
		if (!!doAction)
		{
			InPressed ? doAction->OnAim() : doAction->OffAim();
			bAim = InPressed;
		}
	}
}

void UCActionComponent::OffAllCollisions()
{
	for (const auto& data : Datas)
	{
		if (data == nullptr)
			continue;

		if (data->GetWeapon() == nullptr)
			continue;

		data->GetWeapon()->OffCollision();
	}
}

void UCActionComponent::End_Dead()
{
	for (int32 i = 0; i < (int32)EActionType::Max; i++)
	{
		if (!!Datas[i] && !!Datas[i]->GetEquipment())
			Datas[i]->GetEquipment()->Destroy();

		if (!!Datas[i] && !!Datas[i]->GetWeapon())
			Datas[i]->GetWeapon()->Destroy();

		if (!!Datas[i] && !!Datas[i]->GetDoAction())
			Datas[i]->GetDoAction()->Destroy();

		if (!!Datas[i] && !!Datas[i]->GetReload())
			Datas[i]->GetReload()->Destroy();
	}
}