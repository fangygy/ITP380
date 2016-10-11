//
//  Checkpoint.hpp
//  Game-mac
//
//  Created by Yizheng Fang on 10/25/15.
//  Copyright © 2015 Sanjay Madhav. All rights reserved.
//

#ifndef Checkpoint_hpp
#define Checkpoint_hpp

#include <stdio.h>
#include "Actor.h"
#include "MeshComponent.h"
#include "Mesh.h"
//#include "SphereCollision.h"
class Checkpoint:public Actor
{
    DECL_ACTOR(Checkpoint,Actor);
public:
    Checkpoint(Game &game);
    void BeginTouch(Actor &other) override;
private:
    MeshComponentPtr meshComp;
    MeshPtr mptr;
    //SphereCollisionPtr coll;
};
DECL_PTR(Checkpoint);
#endif /* Checkpoint_hpp */
