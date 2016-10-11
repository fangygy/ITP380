// Fill out your copyright notice in the Description page of Project Settings.

#include "lab5.h"
#include "DwarfAIController.h"
#include "DwarfCharacter.h"
//#include "lab5Character.h"



void ADwarfAIController::BeginPlay()
{
    /*
    Super::BeginPlay();
    APawn *pawn = UGameplayStatics::GetPlayerPawn(this, 0);
    if(pawn)
    {
        MoveToActor(pawn);
    }*/
    
    CurrentState= DwarfState::Start;
}

void ADwarfAIController::OnDwarfDie()
{
    CurrentState=DwarfState::Dead;
}
void ADwarfAIController::Tick(float deltaTime)
{
    Super::Tick(deltaTime);
    
    
    if(CurrentState==DwarfState::Start)
    {
        ChasePlayer();
    }
    else if(CurrentState==DwarfState::Attack)
    {
       // printf("helo");
        ADwarfCharacter* dwarfPawn=Cast<ADwarfCharacter>(GetPawn());
        APawn* pawn = UGameplayStatics::GetPlayerPawn(this, 0);
        float dist= FVector::Dist(dwarfPawn->GetActorLocation(),pawn->GetActorLocation());
        if(dist>150.0f)
        {
            ChasePlayer();
            dwarfPawn->StopAttack();
        }
    }
    
}

void ADwarfAIController::ChasePlayer()
{
    APawn *pawn = UGameplayStatics::GetPlayerPawn(this, 0);
    if(pawn)
    {
        MoveToActor(pawn);
        CurrentState=DwarfState::Chase;
    }

}

void ADwarfAIController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
    // printf("helo on move completed");
    if(Result ==EPathFollowingResult::Success)
    {
        //printf("helo success");
        CurrentState= DwarfState::Attack;
        ADwarfCharacter *dwarfPawn=Cast<ADwarfCharacter>(GetPawn());
        if(dwarfPawn)
        {
        
            dwarfPawn->StartAttack();
        }
    }
}