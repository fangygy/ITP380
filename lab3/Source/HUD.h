//
//  HUD.h
//  Game-mac
//
//  Created by Yizheng Fang on 10/9/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#ifndef __Game_mac__HUD__
#define __Game_mac__HUD__

#include <stdio.h>
#include "Actor.h"
//#include "GameMode.h"
#include "FontComponent.h"

class HUD:public Actor
{
    DECL_ACTOR(HUD,Actor);
public:
    HUD(Game &game);
    FontComponentPtr GetHealth(){return health;}
    FontComponentPtr GetMoney(){return money;}
    FontComponentPtr GetMessage(){return message;}
    void ShowMessage();
    void HideMessage();
private:
   // GameModePtr stats;
    FontComponentPtr mFontComp;
    FontPtr mFont;
    FontComponentPtr health;
    FontComponentPtr money;
    FontComponentPtr message;
};
DECL_PTR(HUD);
#endif /* defined(__Game_mac__HUD__) */
