//
//  AudioComponent.h
//  Game-mac
//
//  Created by Yizheng Fang on 9/20/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//
#pragma once
#ifndef __Game_mac__AudioComponent__
#define __Game_mac__AudioComponent__

#include <stdio.h>
#include "Component.h"
#include "Sound.h"
#include <SDL/SDL_mixer.h>
class SoundCue
{
public:
    SoundCue()
    {
        mChannel=-1;
    };
    SoundCue(int i)
    {
        mChannel=i;
    };
    void Pause()
    {
        if(mChannel!=-1)
            Mix_Pause(mChannel);
    };
    void Resume()
    {
        if(mChannel!=-1)
            Mix_Resume(mChannel);
    };
    void Stop()
    {
        if(mChannel!=-1)
            Mix_HaltChannel(mChannel);
    };
    bool IsPlaying()
    {
        if(mChannel!=-1)
            return Mix_Playing(mChannel);
        return false;
    };
    bool IsPaused()
    {
        if(mChannel!=-1)
            return Mix_Paused(mChannel);
        return true;
    };
private:
    int mChannel;
};

class AudioComponent:public Component
{
    DECL_COMPONENT(AudioComponent, Component);
public:
    AudioComponent(Actor& owner);
    SoundCue PlaySound(SoundPtr sound, bool looping=false);
private:
    
};
DECL_PTR(AudioComponent);
#endif /* defined(__Game_mac__AudioComponent__) */
