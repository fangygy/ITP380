//
//  Sound.cpp
//  Game-mac
//
//  Created by Yizheng Fang on 9/20/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "Sound.h"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>

Sound::Sound()
{
    mData=nullptr;
}

Sound::~Sound()
{
    if(mData!=nullptr)
    {
        Mix_FreeChunk(mData);
    }
}

bool Sound::Load(const char* fileName, class AssetCache* cache)
{
    mData= Mix_LoadWAV(fileName);
    if(mData==nullptr)
    {
        SDL_Log("Error: Sound file failed to load");
        return false;
    }
    
    return true;
}

Mix_Chunk* Sound::GetData()
{
    return mData;
}