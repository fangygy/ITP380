//
//  CameraComponent.cpp
//  Game-mac
//
//  Created by Yizheng Fang on 10/25/15.
//  Copyright © 2015 Sanjay Madhav. All rights reserved.
//

#include "CameraComponent.h"
#include "Actor.h"
#include "Renderer.h"
#include "Game.h"
#include <iostream>
using namespace std;
IMPL_COMPONENT(CameraComponent,Component);

CameraComponent::CameraComponent(Actor & owner): Component(owner)
{
    //cameraVelocity =Vector3(0,0,0);
    spring=200.0f;
    damp=2.0f*sqrt(spring);
}

void CameraComponent:: CalculateIdealPosition()
{
    
    forward=mOwner.GetForward();
    up =mOwner.GetWorldTransform().GetZAxis();
    forward.Normalize();
  
    up.Normalize();
     targetPosition=mOwner.GetPosition();
    targetPosition+=forward*150.0f;
    
    float hor= Math::Lerp(200.0f,250.0f, move->GetLinearAxis()/move->GetLinearSpeed());
    IdealPosition=mOwner.GetPosition()-forward*hor+up*100.0f;
    
    
 
    
    
}
void CameraComponent::setCameraPosition()
{
    //CalculateIdealPosition();
    targetPosition.x =140.0f;
    targetPosition.y=-10.0f;
    targetPosition.z=0.0f;
    IdealPosition.x=-210.0f;
    IdealPosition.y=-10.0f;
    IdealPosition.z=100.0f;
    cameraPosition =IdealPosition;
    cameraForward=targetPosition-cameraPosition;
    cameraForward.Normalize();
    cameraLeft=Cross(up, cameraForward);
    cameraLeft.Normalize();
    cameraUp=Cross(cameraForward,cameraLeft);
    cameraUp.Normalize();
    
    cameraMatrix= Matrix4::CreateLookAt(cameraPosition,targetPosition,cameraUp);
    mOwner.GetGame().GetRenderer().UpdateViewMatrix(cameraMatrix);
    
}
void CameraComponent::Tick(float deltaTime)
{
    
   
    CalculateIdealPosition();
        /*
    cout<<IdealPosition.x<<endl;
    cout<<IdealPosition.y<<endl;
    cout<<IdealPosition.z<<endl;
    cout<<"***************"<<endl;
     */
    
    Vector3 disp=cameraPosition-IdealPosition;
    Vector3 accel=(-spring*disp)-(damp*cameraVelocity);
    cameraVelocity+=accel*deltaTime;
    cameraPosition+=cameraVelocity*deltaTime;
    
    cameraForward=targetPosition-cameraPosition;
    cameraForward.Normalize();
    cameraLeft=Cross(up, cameraForward);
    cameraLeft.Normalize();
    cameraUp=Cross(cameraForward,cameraLeft);
    cameraUp.Normalize();

    cameraMatrix= Matrix4::CreateLookAt(cameraPosition,targetPosition,cameraUp);
    mOwner.GetGame().GetRenderer().UpdateViewMatrix(cameraMatrix);
    
}