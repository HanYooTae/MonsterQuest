#include "CNpc.h"
#include "CPlayer.h"

#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"

#include "Widgets/CInteract.h"

#include "CHelpers.h"

ACNpc::ACNpc()
{
	PrimaryActorTick.bCanEverTick = true;

	// Sphere Settings
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(RootComponent);
	Sphere->SetRelativeLocation(FVector(0, 0, 0));
	Sphere->SetSphereRadius(300.f);

	// SkeletalMesh Settings
	GetMesh()->SetRelativeLocation(FVector(0, 0, -88));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

	USkeletalMesh* meshAsset;
	ConstructorHelpers::FObjectFinder<USkeletalMesh> asset(L"SkeletalMesh'/Game/NPC/_Asset/BattleWizardPolyart/Meshes/WizardSM.WizardSM'");
	meshAsset = asset.Object;

	GetMesh()->SetSkeletalMesh(meshAsset);

	// Widget Settings
	ConstructorHelpers::FClassFinder<UUserWidget> widgetAsset(L"WidgetBlueprint'/Game/Widgets/Interact/WB_Interact.WB_Interact_C'");
	InteractWidgetClass = widgetAsset.Class;
}

void ACNpc::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ACNpc::BeginOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ACNpc::EndOverlap);

	InteractWidget = CreateWidget<UCInteract>(GetWorld(), InteractWidgetClass);
	CheckNull(InteractWidget);

	InteractWidget->AddToViewport();
	InteractWidget->SetVisibility(ESlateVisibility::Hidden);
}

void ACNpc::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACNpc::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACPlayer* player = Cast<ACPlayer>(OtherActor);
	CheckNull(player);

	CheckNull(InteractWidget);
	InteractWidget->SetVisibility(ESlateVisibility::Visible);
	
	//player->OnCharacterBeginOverlap.AddDynamic(this, &ACNpc::OnInteract);
}

void ACNpc::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ACPlayer* player = Cast<ACPlayer>(OtherActor);
	CheckNull(player);

	CheckNull(InteractWidget);
	InteractWidget->SetVisibility(ESlateVisibility::Hidden);
}

void ACNpc::OnInteract()
{
	
}