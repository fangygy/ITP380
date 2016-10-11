// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Sound/SoundCue.h"
#include "lab5Character.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class LAB5_API AWeapon : public AActor
{
	GENERATED_BODY()
  
public:	
	// Sets default values for this actor's properties
    
	AWeapon();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    USkeletalMeshComponent* GetWeaponMesh(){return WeaponMesh;}
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
    
    UAudioComponent* PlayWeaponSound(USoundCue* Sound);
    UParticleSystemComponent* PlayWeaponEffect(UParticleSystem* System);
    Alab5Character* GetMyOwner(){return MyOwner;}
    void SetMyOwner(Alab5Character* character){MyOwner=character;}
    void OnStartFire();
    void OnStopFire();
    void WeaponTrace();
protected:
    UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly,Category = Weapon)
    USkeletalMeshComponent* WeaponMesh;
    
    //sound declarations
    UPROPERTY(EditDefaultsOnly, Category = Sound)
    class USoundCue* FireLoopSound;
    UPROPERTY(EditDefaultsOnly, Category = Sound)
    class USoundCue* FireFinishSound;
    UPROPERTY(Transient)
    class UAudioComponent* FireAC;

    //particle declarations(weapon)
    UPROPERTY(EditDefaultsOnly, Category =Effects)
    class UParticleSystem* MuzzleFX;
    UPROPERTY(Transient)
    class UParticleSystemComponent* MuzzleFXSysComponent;
    
    //particle and data(hit)
    UPROPERTY(EditAnywhere)
    float FireRate;
    UPROPERTY(EditAnywhere)
    float FireRange;
    UPROPERTY(EditDefaultsOnly)
    class UParticleSystem* hitEffect;
    UPROPERTY(EditAnywhere, Category = Damage)
    float Damage = 2.0f;
    
    Alab5Character* MyOwner;
    FTimerHandle WeaponTimer;
    
    
};
