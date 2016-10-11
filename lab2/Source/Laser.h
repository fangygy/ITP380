//
//  Laser.h
//  Game-mac
//
//  Created by Yizheng Fang on 9/8/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//
#pragma once
#ifndef __Game_mac__Laser__
#define __Game_mac__Laser__

#include <stdio.h>
#include <stdio.h>
#include "Actor.h"
#include "MoveComponent.h"
#include "Texture.h"
#include "SpriteComponent.h"
#include "AudioComponent.h"
#include "InputComponent.h"

class Laser: public Actor
{
    DECL_ACTOR(Laser, Actor);
public:
    Laser(Game& game);
    void Tick(float deltaTime) override;
    void BeginTouch(Actor &other) override;
    void BeginPlay() override;
    void OnDieTimer();
    MoveComponentPtr GetMoveComponent();
private:
    MoveComponentPtr move;
    SpriteComponentPtr spriteComp;
    TexturePtr laserTexture;
   // float lifeSpan;
    SoundPtr asteroidSd;
    AudioComponentPtr adc;
    
};
DECL_PTR(Laser);

#endif /* defined(__Game_mac__Laser__) */
