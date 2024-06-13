#include "Actions/Weapons/CMagazine.h"

#include "Components/StaticMeshComponent.h"

#include "Global.h"

ACMagazine::ACMagazine()
{
	CHelpers::CreateActorComponent<USceneComponent>(this, &Root, "Root");
	CHelpers::CreateSceneComponent<UStaticMeshComponent>(this, &Mesh, "Mesh", Root);
	CHelpers::CreateSceneComponent<UStaticMeshComponent>(this, &Mesh_Empty, "Mesh_Empty", Root);

	Mesh->SetCollisionProfileName("Magazine");
	Mesh_Empty->SetCollisionProfileName("Magazine");
}

void ACMagazine::BeginPlay()
{
	Super::BeginPlay();
	
	if (bEject == false)
	{
		Mesh->SetVisibility(true);
		Mesh_Empty->SetVisibility(false);
	}
}

void ACMagazine::Eject()
{
	bEject = true;

	Mesh->SetVisibility(false);
	Mesh_Empty->SetSimulatePhysics(true);
}
