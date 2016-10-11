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
    ActorPtr hpParent=Actor::Spawn(mGame);
    health=FontComponent::Create(*hpParent);
    health->SetFont(mFont);
    health->SetText("Base Health: 10",Color::Blue);
    hpParent->SetPosition(Vector3(-430,320,0));
    
    ActorPtr moneyParent=Actor::Spawn(mGame);
    money=FontComponent::Create(*moneyParent);
    money->SetFont(mFont);
    money->SetText("Money: $100",Color::Green);
    moneyParent->SetPosition(Vector3(-430,290,0));
   
    ActorPtr messageParent=Actor::Spawn(mGame);
    message=FontComponent::Create(*messageParent);
    message->SetFont(mFont);
    message->SetText("my message",Color::Red);
    messageParent->SetPosition(Vector3(-60,0,0));
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