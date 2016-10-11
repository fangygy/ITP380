//
//  Ship.h
//  Game-mac
//
//  Created by Yizheng Fang on 9/8/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//
#pragma once
#ifndef __Game_mac__Ship__
#define __Game_mac__Ship__



#include <stdio.h>
#include "Actor.h"
//#include "MoveComponent.h"
#include "Texture.h"
#include "SpriteComponent.h"
#include "AudioComponent.h"
#include "InputComponent.h"
#include "MoveComponent.h"
#include "MeshComponent.h"
#include "CameraComponent.h"
class Ship: public Actor
{
    DECL_ACTOR(Ship, Actor);
public:
    Ship(Game& game);
    void Tick(float deltaTime) override;
    void FireMissle();
    void BeginPlay() override;
    void BeginTouch(Actor& other) override;
    void OnRespawnShip();
    void Recenter();
    MoveComponentPtr GetMoveComponent();
    
private:
    InputComponentPtr move;
   
    //SpriteComponentPtr spriteComp;
    CameraComponentPtr camComp;
    MeshComponentPtr meshComp;
    MeshPtr mptr;
    TexturePtr shipTexture;
    TexturePtr thrustTexture;
    AudioComponentPtr adcPtr;
    SoundPtr shipDie;
    SoundPtr sd;
    SoundPtr sdEngine;
    SoundPtr sdFire;
    SoundCue sc;
};
DECL_PTR(Ship);


#endif /* defined(__Game_mac__Ship__) */
