#include "Actions/Weapons/CBullet.h"

#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Materials/MaterialInstanceConstant.h"

#include "Global.h"

ACBullet::ACBullet()
{
	CHelpers::CreateSceneComponent<UCapsuleComponent>(this, &Capsule, "Capsule");
	CHelpers::CreateSceneComponent<UStaticMeshComponent>(this, &Mesh, "Mesh", Capsule);
	CHelpers::CreateActorComponent<UProjectileMovementComponent>(this, &Projectile, "Projectile");

	Capsule->SetRelativeRotation(FRotator(90, 0, 0));
	Capsule->SetCapsuleHalfHeight(50);
	Capsule->SetCapsuleRadius(2);
	//Capsule->SetCollisionProfileName("BlockAllDynamic");
	//Capsule->IgnoreActorWhenMoving(GetOwner(), true);

	UStaticMesh* mesh;
	CHelpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/Meshes/Sphere.Sphere'");
	Mesh->SetStaticMesh(mesh);
	Mesh->SetRelativeScale3D(FVector(1, 0.025f, 0.025f));
	Mesh->SetRelativeRotation(FRotator(90, 0, 0));

	UMaterialInstanceConstant* material;
	CHelpers::GetAsset<UMaterialInstanceConstant>(&material, "MaterialInstanceConstant'/Game/Materials/M_Bullet_Inst.M_Bullet_Inst'");
	Mesh->SetMaterial(0, material);

	InitialLifeSpan = 3.f;

	Projectile->InitialSpeed = 2000.f;
	Projectile->MaxSpeed = 4000.f;
	Projectile->ProjectileGravityScale = 0.f;
}

void ACBullet::BeginPlay()
{
	Capsule->OnComponentBeginOverlap.AddDynamic(this, &ACBullet::OnComponentBeginOverlap);

	Super::BeginPlay();
}

void ACBullet::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	CheckTrue(OtherActor == GetOwner());

	if (OnBeginOverlap.IsBound())
		OnBeginOverlap.Broadcast(SweepResult);

	//Destroy();
}
