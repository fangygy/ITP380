//
//  Checkpoint.cpp
//  Game-mac
//
//  Created by Yizheng Fang on 10/25/15.
//  Copyright © 2015 Sanjay Madhav. All rights reserved.
//

#include "Checkpoint.h"
#include "Game.h"
#include "SphereCollision.h"
IMPL_ACTOR(Checkpoint, Actor);

Checkpoint::Checkpoint(Game &game):Actor(game)
{
    meshComp =MeshComponent::Create(*this);
    AssetCache& assetCache = game.GetAssetCache();

    mptr=assetCache.Load<Mesh>("Meshes/Checkpoint.itpmesh2");
    meshComp->SetMesh(mptr);
    
    auto coll = SphereCollision::Create(*this);
    coll->RadiusFromMesh(mptr);
    coll->SetScale(0.75f);
}

void Checkpoint::BeginTouch(Actor& other)
{
    
      Super::BeginTouch(other);
     
     
     if(IsA<Ship>(other))
     {
         this->SetIsAlive(false);
         meshComp->SetIsVisible(false);
         mGame.GetGameMode()->CollectPoint();
     }
}
