//
//  Enemy.h
//  Game-mac
//
//  Created by Yizheng Fang on 10/5/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//
#pragma once
#ifndef __Game_mac__Enemy__
#define __Game_mac__Enemy__

#include <stdio.h>
#include "Actor.h"
#include "MeshComponent.h"
//#include "MoveComponent.h"
#include "AudioComponent.h"
#include "NavComponent.h"
class Enemy:public Actor
{
    DECL_ACTOR(Enemy,Actor);
public:
    Enemy(Game &game);
    void BeginTouch(Actor &other) override;
    void BeginPlay() override;
    void EndPlay() override;
    void Slow();
    void Unslow();
    MeshComponentPtr GetMeshComponent(){return meshComp;}
    NavComponentPtr GetMoveComponent(){return move;}
private:
    MeshComponentPtr meshComp;
    NavComponentPtr move;
    int hp;
    SoundPtr dieSd;
    AudioComponentPtr adc;
};
DECL_PTR(Enemy);
#endif /* defined(__Game_mac__Enemy__) */
