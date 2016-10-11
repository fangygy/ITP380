//
//  NavComponent.h
//  Game-mac
//
//  Created by Yizheng Fang on 10/7/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#ifndef __Game_mac__NavComponent__
#define __Game_mac__NavComponent__

#include <stdio.h>
#include "MoveComponent.h"
#include "PathNode.h"
class NavComponent:public MoveComponent
{
    DECL_COMPONENT(NavComponent,MoveComponent);
public:
    NavComponent(Actor &owner);
    void FollowPath();
    void Tick(float deltaTime) override;
private:
    PathNode* next;
    PathNode start;
};
DECL_PTR(NavComponent);
#endif /* defined(__Game_mac__NavComponent__) */
