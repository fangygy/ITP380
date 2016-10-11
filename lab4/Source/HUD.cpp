//
//  HUD.cpp
//  Game-mac
//
//  Created by Yizheng Fang on 10/9/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "HUD.h"
#include "Game.h"
#include "Font.h"
IMPL_ACTOR(HUD,Actor);

HUD::HUD(Game &game):Actor(game)
{
    //stats= GameMode::Spawn(game);
        mFont= mGame.GetAssetCache().Load<Font>("Fonts/Carlito-Regular.ttf");
  
    }
void HUD:: BeginPlay()
{

    auto hpParent=Actor::Spawn(mGame);
    score=FontComponent::Create(*hpParent);
    score->SetFont(mFont);
    
    score->SetText("Score: 0",Color::White);
    hpParent->SetPosition(Vector3(-30,320,0));
    
    auto timeParent=Actor::Spawn(mGame);
    time=FontComponent::Create(*timeParent);
    time->SetFont(mFont);
    time->SetText("Time: 15",Color::Green);
    timeParent->SetPosition(Vector3(-30,290,0));
    
    auto messageParent=Actor::Spawn(mGame);
    message=FontComponent::Create(*messageParent);
    message->SetFont(mFont);
    message->SetText("Game Over",Color::Red);
    messageParent->SetPosition(Vector3(-30,0,0));
    message->SetIsVisible(false);

}

void HUD::ShowMessage()
{
    message->SetIsVisible(true);
    TimerHandle th;
    mGame.GetGameTimers().SetTimer(th,this,&HUD::HideMessage,3.0f);

}

void HUD::HideMessage()
{
    message->SetIsVisible(false);
}