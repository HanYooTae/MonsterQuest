#include "CPlayer/CPlayer.h"

#include "ActorComponents/CStatusComponent.h"
#include "ActorComponents/CStateComponent.h"
#include "ActorComponents/CMontagesComponent.h"
#include "ActorComponents/CActionComponent.h"
#include "ActorComponents/COptionComponent.h"

#include "Actions/Weapons/CWeapon.h"
#include "Actions/Weapons/CWeapon_Sword.h"
#include "Actions/DoActions/CDoAction.h"
#include "Actions/Reload/CReload.h"
#include "Widgets/HUD/CUserWidget_CrossHair.h"
#include "Widgets/HUD/CUserWidget_Information.h"

#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

#include "Global.h"

ACPlayer::ACPlayer()
{
	// Create CharacterComponent
	CHelpers::CreateActorComponent(this, &Action, "Action");
	CHelpers::CreateActorComponent(this, &State, "State");
	CHelpers::CreateActorComponent(this, &Status, "Status");
	CHelpers::CreateActorComponent(this, &Montages, "Montages");
	CHelpers::CreateActorComponent(this, &Option, "Option");
	CHelpers::CreateActorComponent<ACWeapon>(this, &Weapon, "Weapon");

	CHelpers::GetClass<UCUserWidget_CrossHair>(&CrossHairClass, "WidgetBlueprint'/Game/Widgets/HUD/WB_CrossHair.WB_CrossHair_C'");
	CHelpers::GetClass<UCUserWidget_Information>(&InformationClass, "WidgetBlueprint'/Game/Widgets/HUD/WB_Information.WB_Information_C'");

	CHelpers::CreateSceneComponent(this, &Backpack, "Backpack", GetMesh());
	UStaticMesh* staticMesh;
	CHelpers::GetAsset<UStaticMesh>(&staticMesh, "StaticMesh'/Game/Weapons/Backpack/Backpack.Backpack'");
	Backpack->SetStaticMesh(staticMesh);
	Backpack->SetupAttachment(GetMesh(), "Backpack");

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
	FollowCamera->SetRelativeLocation(FVector(-30, 50, 80));
}

void ACPlayer::BeginPlay()
{
	Super::BeginPlay();

	if (!!CrossHairClass)
	{
		CrossHair = CreateWidget<UCUserWidget_CrossHair, APlayerController>(this->GetController<APlayerController>(), CrossHairClass);
		CrossHair->AddToViewport();
		CrossHair->SetVisibility(ESlateVisibility::Hidden);
	}

	if (!!InformationClass)
	{
		Information = CreateWidget<UCUserWidget_Information, APlayerController>(this->GetController<APlayerController>(), InformationClass);
		Information->AddToViewport();
		Information->SetVisibility(ESlateVisibility::Visible);
	}
}

void ACPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPlayer::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	// Draw Weapon
	PlayerInputComponent->BindAction("Sword", IE_Pressed, this, &ACPlayer::DrawSword);
	PlayerInputComponent->BindAction("Pistol", IE_Pressed, this, &ACPlayer::DrawPistol);
	PlayerInputComponent->BindAction("Rifle", IE_Pressed, this, &ACPlayer::DrawRifle);
	PlayerInputComponent->BindAction("Sniper", IE_Pressed, this, &ACPlayer::DrawSniper);

	// Attack
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &ACPlayer::NormalAttack);
	PlayerInputComponent->BindAction("Attack", IE_Released, this, &ACPlayer::EndAttack);

	// Attack_Fire
	PlayerInputComponent->BindAction("AutoFire", IE_Pressed, this, &ACPlayer::ToggleAutoFire);
	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &ACPlayer::ToggleReload);
	PlayerInputComponent->BindAction("Aim", IE_Pressed, this, &ACPlayer::OnAim);
	PlayerInputComponent->BindAction("Aim", IE_Released, this, &ACPlayer::OffAim);
	
	
	// Move
	PlayerInputComponent->BindAxis("MoveForward", this, &ACPlayer::MoveForward);

	// Turn
	PlayerInputComponent->BindAxis("Turn", this, &ACPlayer::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	// Zoom
	PlayerInputComponent->BindAxis("Zoom", this, &ACPlayer::OnZoom);
}

void ACPlayer::TurnAtRate(float Rate)
{
	CheckFalse(Status->IsCanMove());
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ACPlayer::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ACPlayer::DrawSword()
{
	CheckFalse(State->IsIdleMode());

	Action->SetSwordMode();
}

void ACPlayer::DrawPistol()
{
	CheckFalse(State->IsIdleMode());

	Action->SetPistolMode();
}

void ACPlayer::DrawRifle()
{
	CheckFalse(State->IsIdleMode());

	Action->SetRifleMode();
}

void ACPlayer::DrawSniper()
{
	CheckFalse(State->IsIdleMode());

	Action->SetSniperMode();
}

void ACPlayer::NormalAttack()
{
	if (Action->GetCurrentData()->GetReload() != NULL)
		CheckTrue(Action->GetCurrentData()->GetReload()->bReload);

	Action->DoAction();
}

void ACPlayer::EndAttack()
{
	// 이거 안하면 SwordAttack에 문제생김
	CheckFalse(Action->GetCurrentData()->GetDoAction()->bCanEndAttack);
	Action->GetCurrentData()->GetDoAction()->End_DoAction();
}

void ACPlayer::ToggleAutoFire()
{
	CheckNull(Action->GetCurrentData());
	CheckNull(Action->GetCurrentData()->GetDoAction());
	Action->GetCurrentData()->GetDoAction()->ToggleAutoFire();
}

void ACPlayer::ToggleReload()
{
	CheckNull(Action->GetCurrentData());
	CheckNull(Action->GetCurrentData()->GetDoAction());
	CheckTrue(Action->GetCurrentData()->GetReload()->bReload);
	Action->GetCurrentData()->GetReload()->Reload();
}

void ACPlayer::OnAim()
{
	Action->DoAim(true);
}

void ACPlayer::OffAim()
{
	Action->DoAim(false);
}

void ACPlayer::MoveForward(float Value)
{
	CheckFalse(Status->IsCanMove());
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ACPlayer::OnZoom(float InAxis)
{
	float rate = Option->GetZoomSpeed() * InAxis * GetWorld()->GetDeltaSeconds();
	CameraBoom->TargetArmLength += rate;
	CameraBoom->TargetArmLength = FMath::Clamp(CameraBoom->TargetArmLength, Option->GetZoomMin(), Option->GetZoomMax());
}