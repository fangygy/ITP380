//
//  Ship.cpp
//  Game-mac
//
//  Created by Yizheng Fang on 9/8/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "Ship.h"
#include "Game.h"
#include "SpriteComponent.h"
#include "SphereCollision.h"
#include "Random.h"
//#include "MoveComponent.h"
#include "Laser.h"
#include "Sound.h"
#include "Asteroid.h"
//#include "GameTimers.h"

IMPL_ACTOR(Ship, Actor);


Ship::Ship(Game& game):Actor(game)
{
    meshComp = MeshComponent::Create(*this);
   
    adcPtr=AudioComponent::Create(*this);
    
    AssetCache& assetCache = game.GetAssetCache();
   // shipTexture = assetCache.Load<Texture>("Textures/Spaceship.png");
    mptr=assetCache.Load<Mesh>("Meshes/PlayerShip.itpmesh2");
    meshComp->SetMesh(mptr);
    sdFire= assetCache.Load<Sound>("Sounds/Laser.wav");
    sdEngine=assetCache.Load<Sound>("Sounds/ShipEngine.wav");
    shipDie=assetCache.Load<Sound>("Sounds/ShipDie.wav");
   // thrustTexture=assetCache.Load<Texture>("Textures/SpaceshipWithThrust.png");
    //spriteComp->SetTexture(shipTexture);
   
    SetRotation(Random::GetFloatRange(0.0f, Math::TwoPi));
    move= InputComponent::Create(*this, Component::PreTick);
    move->SetLinearSpeed(400.0f);
    move->SetAngularSpeed(Math::TwoPi);
    sc=adcPtr->PlaySound(sdEngine,1);
    sc.Pause();
    
    auto coll = SphereCollision::Create(*this);
    coll->RadiusFromMesh(mptr);
    coll->SetScale(0.50f);
}
void Ship::OnRespawnShip()
{
    this->SetIsPaused(false);
   //   this->SetPosition(
    meshComp->SetIsVisible(true);
    sc.Resume();
    this->SetPosition(Vector3(0.0f,0.0f,0.0f));
    this->SetRotation(Math::PiOver2);
}
void Ship::BeginTouch(Actor& other)
{
    Super::BeginTouch(other);
    
       
    if(!(this->GetIsPaused())&&IsA<Asteroid>(other))
    {
        this->SetIsPaused(true);
      //  other.SetIsAlive(false);
        adcPtr->PlaySound(shipDie);
        meshComp->SetIsVisible(false);
        sc.Pause();
        TimerHandle handle1;
        mGame.GetGameTimers().SetTimer(handle1,this,&Ship::OnRespawnShip,1.0f);

    }

}
void Ship::FireMissle()
{
    if(!this->GetIsPaused())
    {
    auto mLaser=Laser::Spawn(mGame);
    
    mLaser->SetPosition(this->GetPosition());
    mLaser->SetRotation(this->GetRotation());
    adcPtr->PlaySound(sdFire);
    }
}
void Ship::BeginPlay()
{
    mGame.GetInput().BindAction("Fire", IE_Pressed, this, &Ship::FireMissle);
    move->BindLinearAxis("Move");
    move->BindAngularAxis("Rotate");
   // mGame.GetInput().BindAxis("Move",this,&InputComponent::OnLinearAxis);
    //mGame.GetInput().BindAxis("Rotate",this, &InputComponent::OnAngularAxis);
}
void Ship::Tick(float deltaTime)
{
    Super::Tick(deltaTime);
    if(move->GetLinearAxis()==0)
    {
        sc.Pause();
       // spriteComp->SetTexture(shipTexture);
    }
    else
    {
        sc.Resume();
       // spriteComp->SetTexture(thrustTexture);
    }
}
MoveComponentPtr Ship::GetMoveComponent()
{
    return move;
}