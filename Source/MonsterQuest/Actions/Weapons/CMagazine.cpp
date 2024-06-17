#include "Actions/Weapons/CMagazine.h"

#include "Components/StaticMeshComponent.h"

#include "Global.h"

ACMagazine::ACMagazine()
{
	CHelpers::CreateActorComponent<USceneComponent>(this, &Root, "Root");
	CHelpers::CreateSceneComponent<UStaticMeshComponent>(this, &Mesh, "Mesh", Root);

	Mesh->SetCollisionProfileName("Magazine");
}

void ACMagazine::BeginPlay()
{
	Super::BeginPlay();
	
	if (bEject == false)
	{
		Mesh->SetVisibility(true);
	}
}

void ACMagazine::Eject()
{
	bEject = true;

	Mesh->SetVisibility(true);
	Mesh->SetSimulatePhysics(true);
}
