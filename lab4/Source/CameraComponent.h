//
//  CameraComponent.hpp
//  Game-mac
//
//  Created by Yizheng Fang on 10/25/15.
//  Copyright © 2015 Sanjay Madhav. All rights reserved.
//

#ifndef CameraComponent_h
#define CameraComponent_h

#include <stdio.h>
//#include "Component.h"
#include "Math.h"
#include "MoveComponent.h"
class CameraComponent:public Component
{
    DECL_COMPONENT(CameraComponent,Component);
public:
    CameraComponent(Actor& owner);
    void Tick(float deltaTime) override;
    void setMoveComponent(MoveComponentPtr m){move=m;}
    void CalculateIdealPosition();
    void setCameraPosition();
private:
    Vector3 cameraPosition;
    Vector3 cameraUp;
    Vector3 cameraLeft;
    Vector3 cameraForward;
    Vector3 cameraVelocity;
    Vector3 targetPosition;
    Vector3 IdealPosition;
    Vector3 up;
    Vector3 forward;
    //Vector3 shipPosition;
    Matrix4 cameraMatrix;

    MoveComponentPtr move;
    float spring;
    float damp;
};
DECL_PTR(CameraComponent);
#endif /* CameraComponent_h */
