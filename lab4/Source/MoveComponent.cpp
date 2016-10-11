			#include "MoveComponent.h"
#include "Actor.h"
#include "Game.h"
#include "Renderer.h"

IMPL_COMPONENT(MoveComponent, Component);

MoveComponent::MoveComponent(Actor& owner)
	:Component(owner)
	,mLinearSpeed(0.0f)
	,mAngularSpeed(0.0f)
	,mLinearAxis(0.0f)
	,mAngularAxis(0.0f)
{

}

void MoveComponent::Tick(float deltaTime)
{
	// TODO
    if(!Math::IsZero(mAngularAxis)||!Math::IsZero(mPitchAxis))
    {
        Quaternion incremental= Quaternion(mOwner.GetWorldTransform().GetZAxis(),mAngularAxis*deltaTime);
        Quaternion angle =Concatenate(mOwner.GetRotation(),incremental);
        
        Quaternion pitch = Quaternion(mOwner.GetWorldTransform().GetYAxis(),mPitchAxis*deltaTime);
        Quaternion pitched=Concatenate(angle,pitch);
        mOwner.SetRotation(pitched);
    }
   
    if (!Math::IsZero(mLinearAxis))
    {
        
        // Update velocity based on current forward
        // Update position of owner based on velocity
        mVelocity=mOwner.GetForward()*mLinearSpeed*mLinearAxis;
        Vector3 newPosition =mOwner.GetPosition()+mVelocity*deltaTime;
               mOwner.SetPosition(newPosition);
        
    }
    
}		

void MoveComponent::AddToLinearAxis(float delta)
{
	mLinearAxis += delta;
	mLinearAxis = Math::Clamp(mLinearAxis, -1.0f, 1.0f);
}

void MoveComponent::AddToAngularAxis(float delta)
{
	mAngularAxis += delta;
	mAngularAxis = Math::Clamp(mAngularAxis, -1.0f, 1.0f);
}

void MoveComponent::SetLinearAxis(float axis)
{
	mLinearAxis = Math::Clamp(axis, -1.0f, 1.0f);
}
void MoveComponent::SetPitchAxis(float axis)
{
    mPitchAxis=Math::Clamp(axis, -1.0f, 1.0f);
}

void MoveComponent::SetAngularAxis(float axis)
{
	mAngularAxis = Math::Clamp(axis, -1.0f, 1.0f);
}
