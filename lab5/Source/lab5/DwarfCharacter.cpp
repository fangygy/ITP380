// Fill out your copyright notice in the Description page of Project Settings.

#include "lab5.h"
#include "DwarfCharacter.h"
#include "DwarfAIController.h"
#include "lab5Character.h"

// Sets default values
ADwarfCharacter::ADwarfCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    AIControllerClass = ADwarfAIController::StaticClass();
}

// Called when the game starts or when spawned
void ADwarfCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADwarfCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ADwarfCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

float ADwarfCharacter::TakeDamage(float Damage, FDamageEvent const& DamageEvent,
                                  AController* EventInstigator, AActor* DamageCauser)
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
            // TODO: Process death
            StopAttack();
            float dur=PlayAnimMontage(DeathAnim);
            ADwarfAIController* adac=Cast<ADwarfAIController>(GetController());
            adac->OnDwarfDie();
            GetController()->UnPossess();
            GetWorldTimerManager().SetTimer(OnDeathTimer,this, &ADwarfCharacter::RemoveDwarf,dur-0.15f ,true);
            
        }
    }
    return ActualDamage;
}

void ADwarfCharacter::HitPlayer()
{
    Alab5Character* playerPawn= Cast<Alab5Character>(UGameplayStatics::GetPlayerPawn(this, 0));
     playerPawn->TakeDamage(DwarfDamage, FDamageEvent(), GetInstigatorController(), this);
}
void ADwarfCharacter::StartAttack()
{
    float duration= PlayAnimMontage(AttackAnim);
    GetWorldTimerManager().SetTimer(AttackTimer,this,&ADwarfCharacter::HitPlayer, duration,true);
}

void ADwarfCharacter::StopAttack()
{
    StopAnimMontage(AttackAnim);
    GetWorldTimerManager().ClearTimer(AttackTimer);
    
}

void ADwarfCharacter::RemoveDwarf()
{
   
    Destroy();
}