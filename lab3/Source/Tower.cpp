//
//  Tower.cpp
//  Game-mac
//
//  Created by Yizheng Fang on 10/6/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "Tower.h"
#include "Game.h"
IMPL_ACTOR(Tower,Actor);
Tower::Tower(Game& game):Actor(game)
{
    meshComp=MeshComponent::Create(*this);
    AssetCache& assetCache= mGame.GetAssetCache();
    mesh=assetCache.Load<Mesh>("Meshes/TowerBase.itpmesh2");
    meshComp->SetMesh(mesh);
    
}

void Tower::LoadFrostMesh()
{
    meshComp=MeshComponent::Create(*this);
    AssetCache& assetCache= mGame.GetAssetCache();
    mesh=assetCache.Load<Mesh>("Meshes/Frost.itpmesh2");
    meshComp->SetMesh(mesh);
  }

void Tower::LoadCannonMesh()
{
    meshComp=MeshComponent::Create(*this);
    AssetCache& assetCache= mGame.GetAssetCache();
    mesh=assetCache.Load<Mesh>("Meshes/TowerBase.itpmesh2");
    meshComp->SetMesh(mesh);
}
