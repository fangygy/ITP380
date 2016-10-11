//
//  Enemy.cpp
//  Game-mac
//
//  Created by Yizheng Fang on 10/5/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "Enemy.h"
#include "Game.h"
#include "AssetCache.h"
#include "SphereCollision.h"
#include <iostream>
#include <sstream>
#include "CannonBall.h"
using namespace std;
IMPL_ACTOR(Enemy,Actor);
Enemy::Enemy(Game& game):Actor(game)
{
    meshComp=MeshComponent::Create(*this);
    AssetCache& assetCache= game.GetAssetCache();
    auto mesh=assetCache.Load<Mesh>("Meshes/Peasant.itpmesh2");
    meshComp->SetMesh(mesh);
    dieSd=assetCache.Load<Sound>("Sounds/WilhelmScream.wav");
    adc=AudioComponent::Create(*this);
    auto coll=SphereCollision::Create(*this);
    //coll->RadiusFromMesh(mesh);
    coll->SetScale(1.5f);
    
    move=NavComponent::Create(*this,Component::PreTick);
move->SetLinearSpeed(60.0f);
    move->SetLinearAxis(1.0f);
    hp=3;
}

void Enemy::BeginTouch(Actor &other)
{
    Super::BeginTouch(other);
    if(this->IsAlive()&&IsA<Tile>(other))
    {
        this->SetIsAlive(false);
        other.SetIsAlive(false);
        mGame.GetGameMode()->AttackBase();
        
        stringstream ss;
        ss<<"Base Health: "<<mGame.GetGameMode()->GetBaseHealth();
        std::string temp;
        std::string tempM;
        std::string tempS;
        ss>>temp>>tempM>>tempS;
        //std::cout<<tempM;
        mGame.GetGameMode()->GetHUD()->GetHealth()->SetText(temp+" "+tempM+" "+tempS,Color::Blue);

                ss.clear();

             // adc->PlaySound(asteroidSd);
        
    }
    if(this->IsAlive()&&IsA<CannonBall>(other))
    {
        hp--;
        if(hp==0)
        {
            mGame.GetGameMode()->KillEnemy();
            stringstream ss;
            
            ss<<"Money: $"<<mGame.GetGameMode()->GetMoney();
            std::string temp;
            std::string tempM;
            ss>>temp>>tempM;
            mGame.GetGameMode()->GetHUD()->GetMoney()->SetText(temp+" "+tempM,Color::Green);
            ss.clear();
            adc->PlaySound(dieSd);
            SetIsAlive(false);
        }
        other.SetIsAlive(false);
    }

}
void Enemy::Slow()
{
    move->SetLinearSpeed(30.0f);
    GetMeshComponent()->SetColorIndex(1);
}
void Enemy::Unslow()
{
    move->SetLinearSpeed(60.0f);
    GetMeshComponent()->SetColorIndex(0);
}
void Enemy::BeginPlay()
{
   // Enemy* ep=this;
   mGame.GetWorld().GetEnemy()->insert(this);

}
void Enemy::EndPlay()
{
    mGame.GetWorld().GetEnemy()->erase(this);
}
