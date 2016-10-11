//
//  FrostTower.h
//  Game-mac
//
//  Created by Yizheng Fang on 10/6/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#ifndef __Game_mac__FrostTower__
#define __Game_mac__FrostTower__

#include <stdio.h>
#include "Tower.h"
#include "MeshComponent.h"
#include "Enemy.h"
#include "AudioComponent.h"
class FrostTower:public Tower
{
    DECL_ACTOR(FrostTower,Tower);
public:
    FrostTower(Game &game);
    void FreezeEnemies();
  
    //void BeginPlay() override;
private:
    MeshComponentPtr meshComp;
    AudioComponentPtr adc;
    SoundPtr freezeSd;
    MeshPtr mesh;

};DECL_PTR(FrostTower);
#endif /* defined(__Game_mac__FrostTower__) */
