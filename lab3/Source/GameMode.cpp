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
#include "Enemy.h"
#include <iostream>
#include "SphereCollision.h"
#include "FrostTower.h"
#include "CannonTower.h"
#include "HUD.h"
#include <iostream>
#include <sstream>
using namespace std;
IMPL_ACTOR(GameMode,Actor);

GameMode::GameMode(Game& game):Actor(game)
{
    mWave=0;
    mMoney=100;
    mBaseHealth=10;
    mEnemyCount=0;
    hasSelected=false;
    AssetCache& assetCache= game.GetAssetCache();
    buildSd=assetCache.Load<Sound>("Sounds/Building.wav");
    errorSd=assetCache.Load<Sound>("Sounds/ErrorSound.wav");
 
    adc=AudioComponent::Create(*this);
    
    //initiating pathnodes------------------//
    
  }

GameMode::~GameMode()
{
    for(int i =0;i<9;i++)
    {
         allNodes[i].clear();
    }
    allNodes->clear();
   
    
}
void GameMode:: GameEnds()
{
       SDL_Quit();
}
void GameMode:: AttackBase()
{
    mBaseHealth--;
    if(mBaseHealth==0)
    {
        hud->GetMessage()->SetText("Game Ends: Your Base is Destroyed",Color::Red);
        hud->ShowMessage();
        TimerHandle th;
        mGame.GetGameTimers().SetTimer(th,this,&GameMode::GameEnds,3.0f);
        
    }
}
void GameMode::BeginPlay()
{
    
        hud=HUD::Spawn(mGame);

       mGame.GetInput().BindAction("Select", IE_Pressed,this, &GameMode::changeTileColor);
       mGame.GetInput().BindAction("SpawnFrost",IE_Pressed,this,&GameMode::SpawnFrost);
       mGame.GetInput().BindAction("SpawnCannon",IE_Pressed,this,&GameMode::SpawnCannon);
   
      for(int i =0 ;i<9;i++)
    {
        for(int j= 0;j<18;j++)
        {
           
            auto ast=Tile::Spawn(mGame);
            
            if((i==3||i==4||i==5)&&j==0)
            {
                ast->GetMeshComponent()->SetColorIndex(2);
            }
            if(i==4&&j==1)
            {
                ast->GetMeshComponent()->SetColorIndex(2);
            }
            if(i==4&&j==17)
            {
                ast->GetMeshComponent()->SetColorIndex(3);
                ast->SetRedTileColl();
                
            }
           
            Vector3 tileVec(j*50-430,i*50-200,0.0f);
            ast->SetPosition(tileVec);
            ast->SetScale(1.0f);
            mTiles[i][j]=ast;
            mTiles[i][j]->setBlocked(false);
            
        }
    }
  //  mTiles[4][5]->setBlocked(true);
   // mTiles[3][4]->setBlocked(true);
    /*
    std::vector<PathNode*>  adjacentNodes;
    TilePtr myTile;
    Vector2 gridPosition;
    PathNode* myParent;
    float f;
    float g;
    float h;
    bool isBlocked;
     */
    for(int i=0;i<9;i++)
    {
       //std::vector<PathNode*>* row;
        for(int j =0;j<18;j++)
        {
            
            std::vector<PathNode*> adj;
            PathNode tempNode{adj,mTiles[i][j],Vector2(mTiles[i][j]->GetPosition().x,mTiles[i][j]->GetPosition().y),nullptr,0.0f,0.0f,0.0f,false};
            mGame.GetNavWorld().GetNode(i,j)=tempNode;
        
        }
 
    }
    
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<18;j++)
        {
            std::vector<PathNode*> adjacent;
            if(i-1>=0)
                adjacent.push_back(&mGame.GetNavWorld().GetNode(i-1,j));
            if(i+1<9)
                adjacent.push_back(&mGame.GetNavWorld().GetNode(i+1,j));
            if(j-1>=0)
                adjacent.push_back(&mGame.GetNavWorld().GetNode(i,j-1));
            if(j+1<18)
                adjacent.push_back(&mGame.GetNavWorld().GetNode(i,j+1));
            mGame.GetNavWorld().GetNode(i,j).adjacentNodes=adjacent;
        }
    }
    mGame.GetNavWorld().GetStartNode()=mGame.GetNavWorld().GetNode(4,0);
    mGame.GetNavWorld().GetEndNode()=mGame.GetNavWorld().GetNode(4,17);

    /*
    for(auto adj:mGame.GetNavWorld().GetStartNode().adjacentNodes)
    {
         cout<<adj->myTile->GetPosition().x<<","<<adj->myTile->GetPosition().y<<endl;
        cout<<adj->gridPosition.x<<","<<adj->gridPosition.y<<endl;
    }*/
    mGame.GetNavWorld().TryFindPath();
    SpawnEnemy();
}

void GameMode::SpawnFrost()
{
    if(hasSelected&&mSelected->GetTower()==nullptr&&mMoney>=75)
    {
          mSelected->setBlocked(true);
        if(mGame.GetNavWorld().TryFindPath())
        {
        auto fst=FrostTower::SpawnAttached(*mSelected);
        
        
        auto tc= Tower::SpawnAttached(*fst);
       
        tc->LoadFrostMesh();
        mSelected->SetTower(tc);
        adc->PlaySound(buildSd);
        fst->FreezeEnemies();
            mMoney-=75;
            stringstream ss;
            ss<<"Money: $"<<mMoney;
            std::string temp;
            std::string tempM;
            ss>>temp>>tempM;
            hud->GetMoney()->SetText(temp+" "+tempM,Color::Green);
            ss.clear();
        }
        else
        {
              mSelected->setBlocked(false);
              adc->PlaySound(errorSd);
            hud->GetMessage()->SetText("Cannot Block All Path",Color::Red);
            hud->ShowMessage();
        }
    }
    else
    {
        adc->PlaySound(errorSd);
        if(mMoney<75)
        {
            hud->GetMessage()->SetText("Not Enough Money",Color::Red);
            hud->ShowMessage();
        }
    }
   
}

void GameMode::SpawnCannon()
{
    
    if(hasSelected&&mSelected->GetTower()==nullptr&&mMoney>=50)
    {
        mSelected->setBlocked(true);
        if(mGame.GetNavWorld().TryFindPath())
        {
        auto cst=CannonTower::SpawnAttached(*mSelected);
      
      
        auto tc= Tower::SpawnAttached(*cst);
        tc->LoadCannonMesh();
        mSelected->SetTower(tc);
        adc->PlaySound(buildSd);
        cst->Fire();
            mMoney-=50;
            stringstream ss;
            ss<<"Money: $"<<mMoney;
            std::string temp;
            std::string tempM;
            ss>>temp>>tempM;
            hud->GetMoney()->SetText(temp+" "+tempM,Color::Green);
            ss.clear();
        }
        else
        {
            mSelected->setBlocked(false);
              adc->PlaySound(errorSd);
            hud->GetMessage()->SetText("Cannot Block All Path",Color::Red);
            hud->ShowMessage();
        }
    }
    else
    {
        adc->PlaySound(errorSd);
        if(mMoney<50)
        {
            hud->GetMessage()->SetText("Not Enough Money",Color::Red);
            hud->ShowMessage();
        }

    }
     

}
void GameMode::SpawnEnemy()
{
    
    auto ene=Enemy::Spawn(mGame);
    ene->SetPosition(Vector3(-425.0f,0.0f,0.0f));
    ene->SetScale(1.0f);
    mEnemyCount++;
    if(mEnemyCount==((mWave+1)*5))
    {
        mWave++;
        mEnemyCount=0;
        TimerHandle th;
        mGame.GetGameTimers().SetTimer(th,this,&GameMode::SpawnEnemy,5.0f);
    }
    else
    {
        TimerHandle th;
        mGame.GetGameTimers().SetTimer(th,this,&GameMode::SpawnEnemy,1.0f);
    }
}
void GameMode::changeTileColor()
{
    //58,160  top left corner
    //58,610  bottom left corner
 
    int x;
    int y;
    
    SDL_GetMouseState(&x,&y);
    if(y<610&&y>160&&x>58&&x<958)
    {
      //  cout<<mTiles[(610-y)/50][(x-58)/50]->GetMeshComponent()->GetIndex();
        if(mTiles[(610-y)/50][(x-58)/50]->GetMeshComponent()->GetIndex()==3||mTiles[(610-y)/50][(x-58)/50]->GetMeshComponent()->GetIndex()==2||mTiles[(610-y)/50][(x-58)/50]->GetMeshComponent()->GetIndex()==6||mTiles[(610-y)/50][(x-58)/50]->GetMeshComponent()->GetIndex()==7)
        {
            //doing nothing
        }
        else if(mTiles[(610-y)/50][(x-58)/50]->GetMeshComponent()->GetIndex()==1)
        {
            mTiles[(610-y)/50][(x-58)/50]->GetMeshComponent()->SetColorIndex(0);
            mSelected=nullptr;
            hasSelected=false;
        }
        else
        {
            mTiles[(610-y)/50][(x-58)/50]->GetMeshComponent()->SetColorIndex(1);
            if(mSelected!=nullptr)
            {
                mSelected->GetMeshComponent()->SetColorIndex(0);
            }
            mSelected=mTiles[(610-y)/50][(x-58)/50];
            hasSelected=true;
        }
    }
    
}

