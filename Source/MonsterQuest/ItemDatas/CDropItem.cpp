#include "ItemDatas/CDropItem.h"

#include "CPlayer/CPlayer.h"
#include "ItemDatas/CItemData.h"
#include "Widgets/CInteract.h"

#include "Components/SphereComponent.h"
#include "Engine/SkeletalMesh.h"

#include "Global.h"

ACDropItem::ACDropItem()
{
	CHelpers::CreateSceneComponent(this, &SkeletalMesh, "CDropItem");
	CHelpers::CreateSceneComponent(this, &Sphere, "Sphere", SkeletalMesh);

	RootComponent = SkeletalMesh;

	SkeletalMesh->SetCollisionProfileName("NoCollision");
	SkeletalMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	Sphere->SetSphereRadius(80.0f);

	// Widget Setting
	CHelpers::GetClass(&InteractWidgetClass, "WidgetBlueprint'/Game/Widgets/Interact/WB_Interact.WB_Interact_C'");
}

void ACDropItem::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ACDropItem::BeginOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ACDropItem::EndOverlap);
	
	InteractWidget = CreateWidget<UCInteract>(GetWorld(), InteractWidgetClass);
	CheckNull(InteractWidget);

	InteractWidget->AddToViewport();
	InteractWidget->SetVisibility(ESlateVisibility::Hidden);

	InteractWidget->SetInteractText(ItemData->Item.Interact);
}

void ACDropItem::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACPlayer* player = Cast<ACPlayer>(OtherActor);
	CheckNull(player);

	// Widget visible
	CheckNull(InteractWidget);
	InteractWidget->SetVisibility(ESlateVisibility::Visible);

	player->OnInteract.BindUFunction(this, "OnInteract");
}

void ACDropItem::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ACPlayer* player = Cast<ACPlayer>(OtherActor);
	CheckNull(player);

	// Widget Hidden
	CheckNull(InteractWidget);
	InteractWidget->SetVisibility(ESlateVisibility::Hidden);

	player->OnInteract.Unbind();
}

void ACDropItem::OnInteract()
{
	// Inventory
}