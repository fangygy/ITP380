#include "GameTimers.h"
#include <iostream>
using namespace std;
GameTimerManager::GameTimerManager()
	:mNextTimerId(0)
	,mAreTimersTicking(false)
{

}

void GameTimerManager::Tick(float deltaTime)
{
	// TODO
    mAreTimersTicking = true;
    for( auto &iter : mActiveTimers)
    {
        if(iter.second.mStatus == Active)
        {
           
            iter.second.mRemainingTime-=deltaTime;
        }
        if(iter.second.mRemainingTime<=0.0f)
        {
            iter.second.mDelegate->Execute();
            if(iter.second.mIsLooping)
            {
                iter.second.mRemainingTime=iter.second.mDuration;
            }
            else
            {
                iter.second.mStatus=Cleared;
                mClearedTimers.push_back(iter.second.mHandle);
            }
        }

    }
    
    for( auto &iter: mClearedTimers)
    {
        auto iterA=mActiveTimers.find(iter);
        if(iterA!=mActiveTimers.end())
        {
            RemoveFromObjMap(iterA->second.mObj,iterA->second.mHandle);
            mActiveTimers.erase(iterA);
        }
    }
    mClearedTimers.clear();
   
    for(auto &iter: mPendingTimers)
    {
        iter.second.mStatus=Active;
        mActiveTimers.emplace(iter.first,iter.second );
        
    }
    mPendingTimers.clear();
    mAreTimersTicking=false;
}

void GameTimerManager::ClearTimer(const TimerHandle& handle)
{
	// Is this pending?
	auto iter = mPendingTimers.find(handle);
	if (iter != mPendingTimers.end())
	{
		// We can just remove this from pending timers
		RemoveFromObjMap(iter->second.mObj, handle);
		mPendingTimers.erase(iter);
	}
	else
	{
		iter = mActiveTimers.find(handle);
		if (iter != mActiveTimers.end())
		{
			iter->second.mStatus = Cleared;
			mClearedTimers.push_back(handle);
		}
	}
}

void GameTimerManager::PauseTimer(const TimerHandle& handle)
{
	// Is this pending?
	auto iter = mPendingTimers.find(handle);
	if (iter != mPendingTimers.end())
	{
		iter->second.mStatus = Paused;
	}
	else
	{
		iter = mActiveTimers.find(handle);
		if (iter != mActiveTimers.end())
		{
			iter->second.mStatus = Paused;
		}
	}
}

void GameTimerManager::UnpauseTimer(const TimerHandle& handle)
{
	// Is this pending?
	auto iter = mPendingTimers.find(handle);
	if (iter != mPendingTimers.end())
	{
		iter->second.mStatus = Pending;
	}
	else
	{
		iter = mActiveTimers.find(handle);
		if (iter != mActiveTimers.end())
		{
			iter->second.mStatus = Active;
		}
	}
}

float GameTimerManager::GetRemainingTime(const TimerHandle& handle)
{
	// Is this pending?
	auto iter = mPendingTimers.find(handle);
	if (iter != mPendingTimers.end())
	{
		return iter->second.mRemainingTime;
	}
	else
	{
		iter = mActiveTimers.find(handle);
		if (iter != mActiveTimers.end())
		{
			return iter->second.mRemainingTime;
		}
	}

	// Unknown timer
	return -1.0f;
}

void GameTimerManager::AddTime(const TimerHandle& handle, float time)
{
	// Is this pending?
	auto iter = mPendingTimers.find(handle);
	if (iter != mPendingTimers.end())
	{
		iter->second.mRemainingTime += time;
	}
	else
	{
		iter = mActiveTimers.find(handle);
		if (iter != mActiveTimers.end())
		{
			iter->second.mRemainingTime += time;
		}
	}
}

void GameTimerManager::ClearAllTimers(Object* obj)
{
	auto iter = mObjToHandlesMap.find(obj);
	if (iter != mObjToHandlesMap.end())
	{
		for (auto& t : iter->second)
		{
			ClearTimer(t);
		}

		mObjToHandlesMap.erase(iter);
	}
}

void GameTimerManager::SetTimerInternal(TimerHandle& outHandle, Object* obj, TimerDelegatePtr delegate, float duration, bool looping)
{
	// TODO
    //cout<<GetRemainingTime(outHandle);
    outHandle.mValue=mNextTimerId;
    mNextTimerId++;
    TimerInfo ti;
    ti.mObj=obj;
    ti.mDelegate=delegate;
    ti.mDuration=duration;
    ti.mRemainingTime=duration;
    ti.mIsLooping=looping;
    ti.mHandle=outHandle;
    
    if(mAreTimersTicking)
    {
        
        ti.mStatus=Active;
        mActiveTimers.emplace(outHandle,ti);
    }
    else
    {
        ti.mStatus=Pending;
        mPendingTimers.emplace(outHandle,ti);

    }
     AddToObjMap(obj,outHandle);


}

void GameTimerManager::AddToObjMap(Object* obj, const TimerHandle& handle)
{
	auto iter = mObjToHandlesMap.find(obj);
	// Do we already know of this object?
	if (iter != mObjToHandlesMap.end())
	{
		iter->second.emplace(handle);
	}
	else
	{
		std::unordered_set<TimerHandle> temp;
		temp.emplace(handle);
		mObjToHandlesMap.emplace(obj, temp);
	}
}

void GameTimerManager::RemoveFromObjMap(Object* obj, const TimerHandle& handle)
{
	auto iter = mObjToHandlesMap.find(obj);
	if (iter != mObjToHandlesMap.end())
	{
		auto handleIter = iter->second.find(handle);
		if (handleIter != iter->second.end())
		{
			iter->second.erase(handleIter);
		}
	}
}
