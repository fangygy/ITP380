//
//  Tile.cpp
//  Game-mac
//
//  Created by Yizheng Fang on 10/5/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "Tile.h"
#include "Game.h"
#include "SphereCollision.h"
//#include "MeshComponent.h"

IMPL_ACTOR(Tile,Actor);

Tile::Tile(Game& game):Actor(game)
{
        meshComp=MeshComponent::Create(*this);
    AssetCache& assetCache= game.GetAssetCache();
    mesh=assetCache.Load<Mesh>("Meshes/Tile.itpmesh2");
    meshComp->SetMesh(mesh);

    
}

void Tile::SetRedTileColl()
{
    auto coll= SphereCollision::Create(*this);
    coll->RadiusFromMesh(mesh);
    coll->SetScale(0.30f);
}
