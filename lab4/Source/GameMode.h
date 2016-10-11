//
//  GameMode.h
//  Game-mac
//
//  Created by Yizheng Fang on 10/5/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//
#pragma once
#ifndef __Game_mac__GameMode__
#define __Game_mac__GameMode__

#include <stdio.h>
#include "Actor.h"

#include "AudioComponent.h"

#include "HUD.h"
#include "Arrow.h"
#include "Ship.h"
class GameMode: public Actor
{
    DECL_ACTOR(GameMode,Actor);
public:
    GameMode(Game& game);
    ~GameMode();
    void BeginPlay() override;
    void changeTileColor();
    void SpawnFrost();
    void SpawnCannon();
    void SpawnEnemy();
    void GameEnds();
    void CollectPoint();
    void TimeDecrement();
    //void SpawnCheckpoint();
    //void KillEnemy(){mMoney+=25;}
    //int GetMoney(){return mMoney;}
    HUDPtr GetHUD(){return hud;}
    //void SetBaseHealth(int hp){mBaseHealth=hp;}
    //int GetBaseHealth(){return mBaseHealth;}
    void AttackBase();
private:
    //tiles
   // TilePtr mTiles[9][18];
    HUDPtr hud;
    ArrowPtr ar;
    ShipPtr ship;
    int score;
    int timeLeft;
    //bool hasSelected;
    //int mMoney;
    //int mBaseHealth;
    //int mWave;
    //int mEnemyCount;
    //TilePtr mSelected;
    AudioComponentPtr adc;
    SoundPtr pointSd;
   // SoundPtr errorSd;
   // std::vector<std::vector<PathNode*>*>* allNodes;
};
DECL_PTR(GameMode);



#endif /* defined(__Game_mac__GameMode__) */
