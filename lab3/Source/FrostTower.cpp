//
//  FrostTower.cpp
//  Game-mac
//
//  Created by Yizheng Fang on 10/6/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "FrostTower.h"
#include "Game.h"

#include <iostream>
using namespace std;
IMPL_ACTOR(FrostTower,Tower);
FrostTower::FrostTower(Game& game):Tower(game)
{
    meshComp=MeshComponent::Create(*this);
    AssetCache& assetCache= game.GetAssetCache();
    mesh=assetCache.Load<Mesh>("Meshes/TowerBase.itpmesh2");
    meshComp->SetMesh(mesh);
    freezeSd=assetCache.Load<Sound>("Sounds/Freeze.wav");
    adc=AudioComponent::Create(*this);
}

void FrostTower::FreezeEnemies()
{
   
    for(auto ene: mGame.GetWorld().GetEnemiesInRange(mParent->GetPosition(),150.0f))
    {
        ene->Slow();
        TimerHandle th;
        mGame.GetGameTimers().SetTimer(th,ene,&Enemy::Unslow,1.0f);
    }
    adc->PlaySound(freezeSd);
    TimerHandle th;
    mGame.GetGameTimers().SetTimer(th,this,&FrostTower::FreezeEnemies,2.0f);

}




