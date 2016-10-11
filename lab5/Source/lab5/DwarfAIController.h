// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "DwarfAIController.generated.h"

/**
 * 
 */
UCLASS()
class LAB5_API ADwarfAIController : public AAIController
{
	GENERATED_BODY()
public:
    void BeginPlay() override;
    void Tick(float deltaTime) override;
    void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result) override;
    void ChasePlayer();
    void OnDwarfDie();
private:
    enum class DwarfState:uint8
    {
        Start,
        Chase,
        Attack,
        Dead
    };
     DwarfState CurrentState;
    
   
};


