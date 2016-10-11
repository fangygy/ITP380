// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "lab5.h"
#include "lab5Character.h"
#include "Weapon.h"
Alab5Character::Alab5Character()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
    dead=false;
	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->AttachTo(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->RelativeRotation = FRotator(-60.f, 0.f, 0.f);
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->AttachTo(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
    
    MyWeapon=nullptr;
}
void Alab5Character::OnStartFire()
{
    
    if(MyWeapon&&!dead)
    {
        MyWeapon->OnStartFire();
    }
}
void Alab5Character::OnStopFire()
{

    if(MyWeapon&&!dead)
    {
        MyWeapon->OnStopFire();
    }
}
void Alab5Character::BeginPlay()
{
    Super::BeginPlay();
    if(WeaponClass)
    {
        UWorld* World=GetWorld();
        if(World)
        {
            FActorSpawnParameters SpawnParams;
            SpawnParams.Owner=this;
            SpawnParams.Instigator=Instigator;
            FRotator Rotation(0.0f,0.0f,-90.0f);
            MyWeapon = World->SpawnActor<AWeapon>(WeaponClass, FVector::ZeroVector,Rotation,SpawnParams);
           
            if(MyWeapon)
            {
                MyWeapon->GetWeaponMesh()->AttachTo(GetMesh(),TEXT("WeaponPoint"));
                MyWeapon->SetMyOwner(this);
            }
        }
    }
   // InputComponent->BindAction("Fire",IE_Pressed,this,&Alab5Character::OnStartFire);
    //InputComponent->BindAction("Fire",IE_Released,this,&Alab5Character::OnStopFire);
}

void Alab5Character::OnPlayerDie()
{
    GetMesh()->Deactivate();
}
float Alab5Character::TakeDamage(float Damage, FDamageEvent const& DamageEvent,AController* EventInstigator, AActor* DamageCauser)
{
    float ActualDamage = Super::TakeDamage(Damage, DamageEvent,
                                           EventInstigator, DamageCauser);
    if (ActualDamage > 0.0f)
    {
        Health -= ActualDamage;
        if (Health <= 0.0f)
        {
            // We're dead, don't allow further damage
            bCanBeDamaged = false;
            OnStopFire();
            dead=true;
            // TODO: Process death
            
            float dur=PlayAnimMontage(DeathAnim);
            APlayerController* PC = Cast<APlayerController>(GetController());
            if (PC)
            {
                PC->SetCinematicMode(true, true, true);
            }
            
          //  GetController()->UnPossess();
            dur-=0.25f;
            GetWorldTimerManager().SetTimer(OnDeathTimer,this, &Alab5Character::OnPlayerDie,dur ,true);

        }
    }
    return ActualDamage;
}