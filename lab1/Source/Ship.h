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
#include "MoveComponent.h"
#include "Texture.h"
#include "SpriteComponent.h"

class Ship: public Actor
{
    DECL_ACTOR(Ship, Actor);
public:
    Ship(Game& game);
    void Tick(float deltaTime) override;
    void FireMissle();
    MoveComponentPtr GetMoveComponent();
private:
    MoveComponentPtr move;
    SpriteComponentPtr spriteComp;
    TexturePtr shipTexture;
    TexturePtr thrustTexture;
    
};
DECL_PTR(Ship);


#endif /* defined(__Game_mac__Ship__) */
