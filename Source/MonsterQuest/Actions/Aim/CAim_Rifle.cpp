#include "Actions/Aim/CAim_Rifle.h"
#include "CPlayer/CPlayer.h"

#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/cameraComponent.h"

#include "Global.h"

UCAim_Rifle::UCAim_Rifle()
{
	CHelpers::GetAsset<UCurveFloat>(&Curve, "CurveFloat'/Game/Assets/CV_Aim.CV_Aim'");
}

void UCAim_Rifle::BeginPlay(ACharacter* InOwnerCharacter)
{
	OwnerCharacter = InOwnerCharacter;

	SpringArm = Cast<USpringArmComponent>(OwnerCharacter->GetComponentByClass(USpringArmComponent::StaticClass()));
	Camera = Cast<UCameraComponent>(OwnerCharacter->GetComponentByClass(UCameraComponent::StaticClass()));

	OnTimeline.BindUFunction(this, "Zooming");
	Timeline.AddInterpFloat(Curve, OnTimeline);
	Timeline.SetPlayRate(5.f);
}

void UCAim_Rifle::Tick(float DeltaTime)
{
	Timeline.TickTimeline(DeltaTime);
}

void UCAim_Rifle::On()
{
	CheckFalse(IsAvailable());
	CheckTrue(bZooming);
	bZooming = true;

	SpringArm->TargetArmLength = 100.f;
	SpringArm->bEnableCameraLag = false;

	Timeline.PlayFromStart();
}

void UCAim_Rifle::Off()
{
	CheckFalse(IsAvailable());
	CheckFalse(bZooming);
	bZooming = false;

	SpringArm->TargetArmLength = 300.f;
	SpringArm->bEnableCameraLag = true;

	Timeline.ReverseFromEnd();
}

void UCAim_Rifle::Zooming(float Output)
{
	Camera->FieldOfView = Output;
}