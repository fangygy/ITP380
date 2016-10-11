//
//  Tower.h
//  Game-mac
//
//  Created by Yizheng Fang on 10/6/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#ifndef __Game_mac__Tower__
#define __Game_mac__Tower__

#include <stdio.h>
#include "Actor.h"
#include "MeshComponent.h"
class Tower:public Actor
{
    DECL_ACTOR(Tower,Actor);
public:
    Tower(Game &game);
    void LoadFrostMesh();
    void LoadCannonMesh();
private:
    MeshComponentPtr meshComp;
    MeshPtr mesh;
    
};
DECL_PTR(Tower);
#endif /* defined(__Game_mac__Tower__) */
