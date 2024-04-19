#include "Actions/Weapons/CWeapon.h"

#include "GameFramework/Character.h"
#include "Components/Shapecomponent.h"

#include "Global.h"

ACWeapon::ACWeapon()
{

}

void ACWeapon::BeginPlay()
{
	OwnerCharacter = Cast<ACharacter>(GetOwner());

	Collision->OnComponentBeginOverlap.AddDynamic(this, &ACWeapon::BeginOverlap);
	Collision->OnComponentEndOverlap.AddDynamic(this, &ACWeapon::EndOverlap);

	OffCollision();

	Super::BeginPlay();
}

void ACWeapon::Attachment(FName InSocketName)
{
	AttachToComponent
	(
		OwnerCharacter->GetMesh(),
		FAttachmentTransformRules(EAttachmentRule::KeepRelative, true),
		InSocketName
	);
}

void ACWeapon::OnCollision()
{
	Collision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void ACWeapon::OffCollision()
{
	Collision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ACWeapon::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	CheckTrue(OwnerCharacter == OtherActor);

	ACharacter* otherCharacter = Cast<ACharacter>(OtherActor);

	if (OnBeginOverlap.IsBound())
	{
		if (!!otherCharacter)
			OnBeginOverlap.Broadcast(OwnerCharacter, this, otherCharacter);
	}
}

void ACWeapon::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	CheckTrue(OwnerCharacter == OtherActor);

	ACharacter* otherCharacter = Cast<ACharacter>(OtherActor);

	if (OnEndOverlap.IsBound())
	{
		if (!!otherCharacter)
			OnEndOverlap.Broadcast(OwnerCharacter, this, otherCharacter);
	}
}
