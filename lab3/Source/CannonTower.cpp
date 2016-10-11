//
//  CannonTower.cpp
//  Game-mac
//
//  Created by Yizheng Fang on 10/6/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "CannonTower.h"
#include "Tower.h"
#include "Game.h"
#include "CannonBall.h"

IMPL_ACTOR(CannonTower,Tower);

CannonTower::CannonTower(Game& game):Tower(game)
{
   
    meshComp=MeshComponent::Create(*this);
   
    AssetCache& assetCache= game.GetAssetCache();
    mesh=assetCache.Load<Mesh>("Meshes/Cannon.itpmesh2");
    meshComp->SetMesh(mesh);
    FireSd=assetCache.Load<Sound>("Sounds/CannonFire.wav");
    adcptr=AudioComponent::Create(*this);
   
    
  
}


void CannonTower::Fire()
{
    
    Enemy* target=mGame.GetWorld().GetClosestEnemy(mGame.GetWorld().GetEnemiesInRange(mParent->GetPosition(),150.0f),mParent->GetPosition(),150.0f);
    if(target!=nullptr)
    {
        
    auto diffVector = target->GetPosition() - mParent->GetPosition();
    diffVector.Normalize();
    
    auto angle = acos(Dot(Vector3::UnitX,diffVector ));

        auto crossVector = Cross( Vector3::UnitX,diffVector);
    if (crossVector.z < 0)
    {
        angle *= -1.0f;
    }
    
    this->SetRotation(angle);
        adcptr->PlaySound(FireSd);
    auto cannonBall = CannonBall::Spawn(mGame);
    cannonBall->SetPosition(mParent->GetPosition());
    cannonBall->SetRotation(angle);
    
    
    }
    TimerHandle th;
    mGame.GetGameTimers().SetTimer(th,this,&CannonTower::Fire,1.0f);
}