//
//  Asteroid.h
//  Game-mac
//
//  Created by Yizheng Fang on 9/7/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//
#pragma once
#ifndef __Game_mac__Asteroid__
#define __Game_mac__Asteroid__

#include <stdio.h>
#include "Actor.h"

class Asteroid: public Actor
{
    DECL_ACTOR(Asteroid, Actor);
public:
    Asteroid(Game& game);
    
};
DECL_PTR(Asteroid);


#endif /* defined(__Game_mac__Asteroid__) */
