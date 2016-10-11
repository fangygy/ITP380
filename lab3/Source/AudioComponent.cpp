//
//  AudioComponent.cpp
//  Game-mac
//
//  Created by Yizheng Fang on 9/20/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "AudioComponent.h"
#include "Actor.h"
#include "Sound.h"


IMPL_COMPONENT(AudioComponent, Component);

AudioComponent::AudioComponent(Actor &owner):Component(owner)
{
    
}

SoundCue AudioComponent::PlaySound(SoundPtr sound, bool looping)
{
    if(looping)
        return SoundCue(Mix_PlayChannel(-1,sound->GetData(),-1));
    else
        return SoundCue(Mix_PlayChannel(-1,sound->GetData(),0));

            
}
