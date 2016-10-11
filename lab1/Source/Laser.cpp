//
//  Laser.cpp
//  Game-mac
//
//  Created by Yizheng Fang on 9/8/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "Laser.h"
#include "Ship.h"
#include "Game.h"
#include "SpriteComponent.h"
#include "Random.h"
#include "MoveComponent.h"
#include "SphereCollision.h"
#include "Asteroid.h"

IMPL_ACTOR(Laser, Actor);


Laser::Laser(Game& game):Actor(game)
{
    spriteComp = SpriteComponent::Create(*this);
    lifeSpan=1.0f;
    
    AssetCache& assetCache = game.GetAssetCache();
    laserTexture = assetCache.Load<Texture>("Textures/Laser.png");
    spriteComp->SetTexture(laserTexture);
    
    SetRotation(Random::GetFloatRange(0.0f, Math::TwoPi));
    move= MoveComponent::Create(*this, Component::PreTick);
    move->SetLinearSpeed(600.0f);
    move->SetLinearAxis(1.0f);
    auto coll = SphereCollision::Create(*this);
    coll->RadiusFromTexture(laserTexture);
    coll->SetScale(0.9f);
    
}

void Laser::BeginTouch(Actor &other)
{
    Super::BeginTouch(other);
    
    if(this->IsAlive()&&IsA<Asteroid>(other))
    {
        this->SetIsAlive(false);
        other.SetIsAlive(false);
        if(other.GetScale()==0.75f)
        {
            for (int i = 0; i < 3; i++)
            {
                auto ast = Asteroid::Spawn(mGame);
                ast->SetPosition(other.GetPosition());
                ast->SetScale(0.25f);
            }

        }
    }
}
void Laser::Tick(float deltaTime)
{
    lifeSpan-=deltaTime;
    if(lifeSpan<0)
    {
        SetIsAlive(false);
    }
}
MoveComponentPtr Laser::GetMoveComponent()
{
    return move;
}