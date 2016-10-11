//
//  CannonTower.h
//  Game-mac
//
//  Created by Yizheng Fang on 10/6/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#ifndef __Game_mac__CannonTower__
#define __Game_mac__CannonTower__

#include <stdio.h>
#include "Tower.h"
#include "MeshComponent.h"
#include "AudioComponent.h"

class CannonTower:public Tower
{
    DECL_ACTOR(CannonTower,Tower);
public:
    CannonTower(Game& game);
    void Fire();
private:
    MeshComponentPtr meshComp;
    MeshPtr mesh;
    SoundPtr FireSd;
    AudioComponentPtr adcptr;

};DECL_PTR(CannonTower);
#endif /* defined(__Game_mac__CannonTower__) */
