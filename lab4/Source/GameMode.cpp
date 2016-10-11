//
//  GameMode.cpp
//  Game-mac
//
//  Created by Yizheng Fang on 10/5/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "GameMode.h"
#include "Game.h"
#include "Random.h"
#include "InputComponent.h"
//#include "Enemy.h"
#include <iostream>
#include "SphereCollision.h"
//#include "FrostTower.h"
//#include "CannonTower.h"
#include "HUD.h"
#include <iostream>
#include <sstream>
#include "Asteroid.h"
#include "Arrow.h"
#include "Checkpoint.h"
using namespace std;
IMPL_ACTOR(GameMode,Actor);

GameMode::GameMode(Game& game):Actor(game)
{
      AssetCache& assetCache= game.GetAssetCache();
   
    adc=AudioComponent::Create(*this);
    pointSd=assetCache.Load<Sound>("Sounds/Checkpoint.wav");
    score =0;
    timeLeft=15;
        
  }

GameMode::~GameMode()
{
   
   
    
}


void GameMode:: GameEnds()
{
       SDL_Quit();
}
void GameMode::CollectPoint()
{
    adc->PlaySound(pointSd);
    Vector3 shipPos = ship->GetPosition();
    Vector3 pointMin = Vector3(shipPos.x-1000-score,shipPos.y-1000-score,shipPos.z-1000-score);
    Vector3 pointMax = Vector3(shipPos.x+1000+score,shipPos.y+1000+score,shipPos.z+1000+score);
    auto cp=Checkpoint::Spawn(mGame);
    cp->SetPosition(Random::GetVector(pointMin,pointMax));
    ar->SetPointPos(cp->GetPosition());
   
    score+=100;
    timeLeft+=5;
    stringstream ss;
    ss<<"Score: "<<score;
    std::string temp;
    std::string tempM;
    ss>>temp>>tempM;
    hud->Getscore()->SetText(temp+" "+tempM,Color::White);
    ss.clear();
    ss<<"Time: "<<timeLeft;

    ss>>temp>>tempM;
    hud->Gettime()->SetText(temp+" "+tempM,Color::Green);
    ss.clear();
   
}
void GameMode::TimeDecrement()
{
    if(timeLeft>=1)
        timeLeft-=1;
    stringstream ss;
    ss<<"Time: "<<timeLeft;
    std::string temp;
    std::string tempM;
    ss>>temp>>tempM;
    hud->Gettime()->SetText(temp+" "+tempM,Color::Green);
    ss.clear();
    TimerHandle th;
    mGame.GetGameTimers().SetTimer(th,this,&GameMode::TimeDecrement,1.0f);
    if(timeLeft<=0)
    {
        mGame.GetShip()->SetIsPaused(true);
        hud->ShowMessage();
        //this->SetIsPaused(true);
    }

}
void GameMode::BeginPlay()
{
    
    ship=mGame.GetShip();
        hud=HUD::Spawn(mGame);
    Vector3 min=  Vector3(-5000,-5000,-5000);
    Vector3 max=Vector3(5000,5000,5000);
    for( int i =0;i<500;i++)
    {
        auto ast= Asteroid::Spawn(mGame);
        ast->SetPosition(Random::GetVector(min,max));
    }
    
    Vector3 shipPos = ship->GetPosition();
    Vector3 pointMin = Vector3(shipPos.x-1000,shipPos.y-1000,shipPos.z-1000);
    Vector3 pointMax = Vector3(shipPos.x+1000,shipPos.y+1000,shipPos.z+1000);
    auto cp=Checkpoint::Spawn(mGame);
    cp->SetPosition(Random::GetVector(pointMin,pointMax));
    
    ar=Arrow::Spawn(mGame);
    ar->SetPlayer(ship);
    ar->SetPointPos(cp->GetPosition());
    TimerHandle th;
    mGame.GetGameTimers().SetTimer(th,this,&GameMode::TimeDecrement,1.0f);
 }

