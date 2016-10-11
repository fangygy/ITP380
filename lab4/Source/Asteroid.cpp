//
//  Asteroid.cpp
//  Game-mac
//
//  Created by Yizheng Fang on 9/7/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "Asteroid.h"
#include "Game.h"
#include "SpriteComponent.h"
#include "Random.h"
#include "MoveComponent.h"
#include "SphereCollision.h"

IMPL_ACTOR(Asteroid, Actor);


Asteroid::Asteroid(Game& game):Actor(game)
{
      	MeshComponentPtr meshComp = MeshComponent::Create(*this);

    
    AssetCache& assetCache = game.GetAssetCache();
    auto mesh = assetCache.Load<Mesh>("Meshes/AsteroidMesh.itpmesh2");
    
    meshComp->SetMesh(mesh);
    Quaternion angle= Quaternion(GetWorldTransform().GetZAxis(),Random::GetFloatRange(0.0f, Math::TwoPi));
    SetRotation(angle);
    //auto move = MoveComponent::Create(*this, Component::PreTick);
    //move->SetLinearSpeed(150.0f);
    //move->SetLinearAxis(1.0f);
    SetScale(0.1f);
    //auto coll = SphereCollision::Create(*this);
    //coll->RadiusFromMesh(mesh);
    //coll->SetScale(0.9f);
}