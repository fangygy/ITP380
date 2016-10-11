//
//  Arrow.cpp
//  Game-mac
//
//  Created by Yizheng Fang on 10/25/15.
//  Copyright © 2015 Sanjay Madhav. All rights reserved.
//

#include "Arrow.h"
#include "Game.h"
IMPL_ACTOR(Arrow,Actor)

Arrow::Arrow(Game &game):Actor(game)
{
    meshComp =MeshComponent::Create(*this);
    AssetCache& assetCache = game.GetAssetCache();
    
    mptr=assetCache.Load<Mesh>("Meshes/Arrow.itpmesh2");
    meshComp->SetMesh(mptr);
    
    
}

void Arrow::BeginPlay()
{
   
    SetPosition(mGame.GetRenderer().Unproject(Vector3(0,150,0.6)));
}

void Arrow::Tick(float deltaTime)
{
 
    Vector3 diff = pointPos - player->GetPosition();
    diff.Normalize();
    
    float angle = acos(Dot(Vector3::UnitX,diff ));
    
    Vector3 cross = Cross( Vector3::UnitX,diff);
    cross.Normalize();
    Quaternion q=Quaternion(cross,angle);
    SetRotation(q);
  SetPosition(mGame.GetRenderer().Unproject(Vector3(0,150,0.6)));
}



