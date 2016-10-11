//
//  MeshComponent.cpp
//  Game-mac
//
//  Created by Yizheng Fang on 9/21/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "MeshComponent.h"
#include "Actor.h"
#include "Renderer.h"
IMPL_COMPONENT(MeshComponent,DrawComponent);

MeshComponent::MeshComponent(Actor& Owner):DrawComponent(Owner)
{
}

void MeshComponent::Draw(class Renderer& render)
{
    if(mptr!=nullptr&&(IsVisible()))
    {
        render.DrawBasicMesh(mptr->GetVertexArray(),mptr->GetTexture(0),this->GetOwner().GetWorldTransform());
    }
}