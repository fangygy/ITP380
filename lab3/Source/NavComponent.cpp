//
//  NavComponent.cpp
//  Game-mac
//
//  Created by Yizheng Fang on 10/7/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "NavComponent.h"
#include "Actor.h"
#include "Game.h"
#include "PathNode.h"
IMPL_COMPONENT(NavComponent,MoveComponent)
NavComponent::NavComponent(Actor &owner):MoveComponent(owner)
{
   // mOwner.GetGame().GetNavWorld().TryFindPath();
    mOwner.GetGame().GetNavWorld().TryFindPath();
    start=mOwner.GetGame().GetNavWorld().GetPath();
   // next=start.myParent;
}

void NavComponent::FollowPath()
{
    
    
    if(start.myParent!=nullptr&& ( fabs(start.gridPosition.x-mOwner.GetPosition().x)+fabs(start.gridPosition.y-mOwner.GetPosition().y))<1.0f)
    {
        start=*start.myParent;
    }
}

void NavComponent::Tick(float deltaTime)
{
    FollowPath();
    auto diffVector = Vector3(start.gridPosition.x,start.gridPosition.y,0) - mOwner.GetPosition();
    diffVector.Normalize();
    
    auto angle = acos(Dot(Vector3::UnitX,diffVector ));
    
    auto crossVector = Cross( Vector3::UnitX,diffVector);
    if (crossVector.z < 0)
    {
        angle *= -1.0f;
    }
    mOwner.SetRotation(angle);

    Super::Tick(deltaTime);
 
}