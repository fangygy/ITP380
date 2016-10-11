//
//  Arrow.hpp
//  Game-mac
//
//  Created by Yizheng Fang on 10/25/15.
//  Copyright © 2015 Sanjay Madhav. All rights reserved.
//

#ifndef Arrow_hpp
#define Arrow_hpp

#include <stdio.h>
#include "Actor.h"
#include "MeshComponent.h"
#include "Mesh.h"
class Arrow:public Actor
{
    DECL_ACTOR(Arrow,Actor);
    
public:
    Arrow(Game& game);
    void SetPointPos(Vector3 v){pointPos=v;}
    void SetPlayer(ActorPtr p){player=p;}
    void BeginPlay() override;
    void Tick(float deltaTime) override;
private:
    MeshComponentPtr meshComp;
    MeshPtr mptr;

    Vector3 pointPos;
    ActorPtr player;
};
DECL_PTR(Arrow);
#endif /* Arrow_hpp */
