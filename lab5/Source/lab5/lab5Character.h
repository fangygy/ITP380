// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "lab5Character.generated.h"

UCLASS(Blueprintable)
class Alab5Character : public ACharacter
{
	GENERATED_BODY()

	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;


public:
	Alab5Character();
    
	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
    void OnStartFire();
    void OnStopFire();
    void OnPlayerDie();
    bool IsDead(){return dead;}
    void BeginPlay() override;
    float TakeDamage(float Damage, FDamageEvent const& DamageEvent,AController* EventInstigator, AActor* DamageCauser) override;
    
protected:
    UPROPERTY(EditAnywhere, Category=Weapon)
    TSubclassOf<class AWeapon> WeaponClass;
private:
    class AWeapon* MyWeapon;
    UPROPERTY(EditAnywhere, Category = Damage)
    float Health = 100.0f;
    bool dead;
    FTimerHandle OnDeathTimer;
   
    UPROPERTY(EditDefaultsOnly)
    UAnimMontage* DeathAnim;
};

