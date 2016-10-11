//
//  MeshComponent.h
//  Game-mac
//
//  Created by Yizheng Fang on 9/21/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//
#pragma once
#ifndef __Game_mac__MeshComponent__
#define __Game_mac__MeshComponent__

#include <stdio.h>
#include "DrawComponent.h"
#include "Mesh.h"
class MeshComponent:public DrawComponent
{
    DECL_COMPONENT(MeshComponent, DrawComponent);
public:
    MeshComponent(Actor& Owner);
    void Draw(class Renderer& render) override;
    void SetMesh(MeshPtr mp){mptr=mp;}
    void SetColorIndex(int ind);
    int GetIndex(){return index;}
    MeshPtr GetMesh(){return mptr;}
private:
    MeshPtr mptr;
    int index;
};
DECL_PTR(MeshComponent);
#endif /* defined(__Game_mac__MeshComponent__) */
