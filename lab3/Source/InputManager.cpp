#include "InputManager.h"
#include <iostream>
using namespace std;
void InputManager::HandleKeyPressed(int key)
{
	// TODO
    auto iter=mKeyToActionMap.find(key);
    if(iter!=mKeyToActionMap.end())
    {
        if(iter->second->mPressedDelegate!=nullptr)
        {
            iter->second->mPressedDelegate->Execute();
        }
    }
    auto iterA=mKeyToAxisMap.find(key);
    if(iterA!=mKeyToAxisMap.end())
    {
        if(iterA->second->mDelegate!=nullptr)
        {
            
           if(iterA->second->mPositiveKey==key)
           {
               iterA->second->mValue+=1.0f;
               iterA->second->mDelegate->Execute(iterA->second->mValue);
           }
           else
           {
               iterA->second->mValue-=1.0f;
                iterA->second->mDelegate->Execute(iterA->second->mValue);
           }
        }
    }
}

void InputManager::HandleKeyReleased(int key)
{
	// TODO
    auto iter=mKeyToActionMap.find(key);
    if(iter!=mKeyToActionMap.end())
    {
        if(iter->second->mReleasedDelegate!=nullptr)
        {
            iter->second->mReleasedDelegate->Execute();
        }
    }
    auto iterA=mKeyToAxisMap.find(key);
    if(iterA!=mKeyToAxisMap.end())
    {
        if(iterA->second->mDelegate!=nullptr)
        {
            if(iterA->second->mPositiveKey==key)
            {
                iterA->second->mValue-=1.0f;
                iterA->second->mDelegate->Execute(iterA->second->mValue);
            }
            else
            {
                iterA->second->mValue+=1.0f;
                iterA->second->mDelegate->Execute(iterA->second->mValue);
            }
        }
    }
}

void InputManager::AddActionMapping(const std::string& name, int key)
{
	// TODO
    ActionMappingPtr ptr=std::make_shared<ActionMapping>();
    ptr->mName=name;
    ptr->mKey=key;
    mNameToActionMap.emplace(name,ptr);
    mKeyToActionMap.emplace(key,ptr);
}

void InputManager::AddAxisMapping(const std::string& name, int positiveKey, int negativeKey)
{
	// TODO
    AxisMappingPtr ptr=std::make_shared<AxisMapping>();
    ptr->mName=name;
 
    ptr->mPositiveKey=positiveKey;
    ptr->mNegativeKey=negativeKey;
   
    ptr->mValue=0;
    mNameToAxisMap.emplace(name,ptr);
    mKeyToAxisMap.emplace(positiveKey,ptr);
    mKeyToAxisMap.emplace(negativeKey,ptr);
}

void InputManager::BindActionInternal(const std::string& name, InputEvent event, ActionDelegatePtr delegate)
{
	// TODO
    auto iter= mNameToActionMap.find(name);
    if(iter!=mNameToActionMap.end())
    {
        if(event==IE_Pressed)
        {
            iter->second->mPressedDelegate=delegate;
        }
        else if(event==IE_Released)
        {
            iter->second->mReleasedDelegate=delegate;
        }
    }
}

void InputManager::BindAxisInternal(const std::string& name, AxisDelegatePtr delegate)
{
	// TODO
   
    auto iter=mNameToAxisMap.find(name);
    
    if(iter!=mNameToAxisMap.end())
    {
       
        
        iter->second->mDelegate=delegate;
        
    }
}
