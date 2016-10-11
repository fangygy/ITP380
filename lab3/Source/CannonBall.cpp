//
//  CannonBall.cpp
//  Game-mac
//
//  Created by Yizheng Fang on 10/7/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "CannonBall.h"
#include "Game.h"
#include "SphereCollision.h"
IMPL_ACTOR(CannonBall,Actor);
CannonBall::CannonBall(Game & game):Actor(game)
{
    meshComp=MeshComponent::Create(*this);
    AssetCache& assetCache= game.GetAssetCache();
    mesh=assetCache.Load<Mesh>("Meshes/CannonBall.itpmesh2");
    meshComp->SetMesh(mesh);
    
    auto coll=SphereCollision::Create(*this);
    coll->RadiusFromMesh(mesh);
    coll->SetScale(0.2f);
    
    move=MoveComponent::Create(*this,Component::PreTick);
    move->SetLinearSpeed(300.0f);
    move->SetLinearAxis(1.0f);
    
    TimerHandle th;
    mGame.GetGameTimers().SetTimer(th,this,&CannonBall::Despawn,3.0f);
}

void CannonBall::Despawn()
{
    this->SetIsAlive(false);
}