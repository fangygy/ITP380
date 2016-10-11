//
//  Tile.h
//  Game-mac
//
//  Created by Yizheng Fang on 10/5/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//
#pragma once
#ifndef __Game_mac__Tile__
#define __Game_mac__Tile__

#include <stdio.h>
#include "Actor.h"
#include "MeshComponent.h"
#include "Tower.h"

class Tile:public Actor
{
     DECL_ACTOR(Tile,Actor);
public:
    Tile(Game &game);
    void SetRedTileColl();
    TowerPtr GetTower(){return mTower;}
    void SetTower(TowerPtr tc){mTower=tc;}
    bool isBlocked(){return blocked;}
    void setBlocked(bool block){blocked =block;}
    MeshComponentPtr GetMeshComponent(){return meshComp;}
   // void BeginPlay() override;
    
private:
    MeshComponentPtr meshComp;
    MeshPtr mesh;
    TowerPtr mTower;
    bool blocked;
    
};DECL_PTR(Tile);
#endif /* defined(__Game_mac__Tile__) */
