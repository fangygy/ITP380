// Fill out your copyright notice in the Description page of Project Settings.

#include "lab5.h"
#include "SpawnManager.h"
#include "Engine/TargetPoint.h"

// Sets default values
ASpawnManager::ASpawnManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnManager::BeginPlay()
{
	Super::BeginPlay();
    GetWorldTimerManager().SetTimer(GameTimer,this,&ASpawnManager::OnSpawnTimer,SpawnTime,true);
}

// Called every frame
void ASpawnManager::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ASpawnManager:: OnSpawnTimer()
{
   // GetWorldTimerManager().SetTimer(SpawnTimer,this, &A:RemoveDwarf,dur-0.15f ,true);
    if(SpawnPoints.Num()!=0)
    {
        int index= FMath::RandRange(0,SpawnPoints.Num()-1);
        FVector vec= SpawnPoints[index]->GetActorLocation();
        FRotator rot= SpawnPoints[index]->GetActorRotation();
        ACharacter* Char = GetWorld()->SpawnActor<ACharacter>(CharacterClass, vec, rot);
        if (Char)
        {
            // Spawn the AI controller for the character
            Char->SpawnDefaultController();
        }
    }
}

