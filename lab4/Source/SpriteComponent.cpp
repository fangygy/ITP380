#include "SpriteComponent.h"
#include "Actor.h"
#include <SDL/SDL.h>
#include "Renderer.h"

IMPL_COMPONENT(SpriteComponent, DrawComponent);

SpriteComponent::SpriteComponent(Actor& owner)
	:DrawComponent(owner)
{

}

void SpriteComponent::Draw(Renderer& render)
{
	// TODO
    if(mTexture!=nullptr)
    {
        
        Matrix4 scale= Matrix4::CreateScale(mTexture->GetWidth(),mTexture->GetHeight(),1);
        Matrix4 wTransform=scale*mOwner.GetWorldTransform();
        render.DrawSprite(mTexture,wTransform);
    }
}

