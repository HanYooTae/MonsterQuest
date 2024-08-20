#include "CPortal.h"

#include "CPlayer/CPlayer.h"
#include "Widgets/CInteract.h"
#include "ItemDatas/CItemData.h"

#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"

#include "Engine/GameInstance.h"

#include "Global.h"

ACPortal::ACPortal()
{
	CHelpers::CreateSceneComponent(this, &Box, "Box", RootComponent);
	CHelpers::CreateSceneComponent(this, &ParticleComponent, "Particle", Box);

	CHelpers::GetClass(&InteractWidgetClass, "WidgetBlueprint'/Game/Widgets/Interact/WB_Interact.WB_Interact_C'");
}

void ACPortal::BeginPlay()
{
	Super::BeginPlay();
	
	Box->OnComponentBeginOverlap.AddDynamic(this, &ACPortal::BeginOverlap);
	Box->OnComponentEndOverlap.AddDynamic(this, &ACPortal::EndOverlap);

	//CheckNull(Particle);
	//ParticleComponent->SetTemplate(Particle);

	InteractWidget = CreateWidget<UCInteract>(GetWorld(), InteractWidgetClass);
	CheckNull(InteractWidget);

	InteractWidget->AddToViewport();
	InteractWidget->SetVisibility(ESlateVisibility::Hidden);

	InteractWidget->SetInteractText(ItemData->Item.Interact);
}

void ACPortal::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACPlayer* player = Cast<ACPlayer>(OtherActor);
	CheckNull(player);

	CheckNull(InteractWidget);
	InteractWidget->SetVisibility(ESlateVisibility::Visible);

	player->OnInteract.BindUFunction(this, "OnInteract");
}

void ACPortal::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ACPlayer* player = Cast<ACPlayer>(OtherActor);
	CheckNull(player);

	CheckNull(InteractWidget);
	InteractWidget->SetVisibility(ESlateVisibility::Hidden);

	player->OnInteract.Unbind();
}

void ACPortal::OnInteract()
{
	UGameplayStatics::OpenLevel(this, TransferLevelName);
}