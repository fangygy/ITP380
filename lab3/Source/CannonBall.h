//
//  CannonBall.h
//  Game-mac
//
//  Created by Yizheng Fang on 10/7/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#ifndef __Game_mac__CannonBall__
#define __Game_mac__CannonBall__

#include <stdio.h>
#include "Actor.h"
#include "MeshComponent.h"
#include "MoveComponent.h"
class CannonBall:public Actor
{
    DECL_ACTOR(CannonBall,Actor);
public:
    CannonBall(Game &game);
    void Despawn();
private:
    MeshComponentPtr meshComp;
    MeshPtr mesh;
    MoveComponentPtr move;
};
DECL_PTR(CannonBall);
#endif /* defined(__Game_mac__CannonBall__) */
