//
//  InputComponent.h
//  Game-mac
//
//  Created by Yizheng Fang on 9/20/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#pragma once
#ifndef __Game_mac__InputComponent__
#define __Game_mac__InputComponent__

#include <stdio.h>
#include "MoveComponent.h"


class InputComponent:public MoveComponent
{
    DECL_COMPONENT(InputComponent, MoveComponent);
public:
    InputComponent(Actor& owner);
    void BindLinearAxis(const std::string& name);
    void BindAngularAxis(const std::string& name);
    void OnLinearAxis(float value);
    void OnAngularAxis(float value);


};
DECL_PTR(InputComponent);

#endif 