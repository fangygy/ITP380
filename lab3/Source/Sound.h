//
//  Sound.h
//  Game-mac
//
//  Created by Yizheng Fang on 9/20/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//
#pragma once
#ifndef __Game_mac__Sound__
#define __Game_mac__Sound__

#include <stdio.h>
#include "Asset.h"

class Sound : public Asset
{
    DECL_ASSET(Sound, Asset);
public:
    Sound();
    ~Sound();
    bool Load(const char* fileName, class AssetCache* cache) override;
    struct Mix_Chunk* GetData();
private:
    struct Mix_Chunk* mData;
};
DECL_PTR(Sound);





#endif /* defined(__Game_mac__Sound__) */
