//
//  NavWorld.cpp
//  Game-mac
//
//  Created by Yizheng Fang on 10/7/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "NavWorld.h"
#include <iostream>
using namespace std;
NavWorld::NavWorld()
{

    
    
}
NavWorld::~NavWorld()
{
    openSet.clear();
    closedSet.clear();
}
bool NavWorld::TryFindPath()
{
      int x =0;
    for(int i = 0;i<9;i++)
    {
        for(int j =0;j<18;j++)
        {
            if(mNodes[i][j].myTile->GetMeshComponent()->GetIndex()>3)
            {
                mNodes[i][j].myTile->GetMeshComponent()->SetColorIndex(mNodes[i][j].myTile->GetMeshComponent()->GetIndex()-4);
            }
          //  mNodes[i][j].myTile->GetMeshComponent()->SetColorIndex(2);
        }
    }
    StartNode.g=0;
    EndNode.g=0;
    PathNode* currentNode=&EndNode;
        closedSet.emplace(currentNode);
    do
    {
        x++;
        for(auto node: currentNode->adjacentNodes)
        {
            auto checkClosed=closedSet.find(node);
            if(checkClosed!=closedSet.end())
            {
                continue;
            }
            auto checkOpen=openSet.find(node);
            if(checkOpen!=openSet.end())
            {
                float new_g=currentNode->g+1;
                if (new_g<node->g)
                {
                    node->myParent=currentNode;
                  node->g=new_g;
                    node->f=node->g+node->h;
                }
            }
            else
            {
                if(!(node->myTile->isBlocked()))
              {
                    node->myParent=currentNode;
                    node->h=(fabs(node->gridPosition.x-StartNode.gridPosition.x)+fabs(node->gridPosition.y-StartNode.gridPosition.y))/50;
                    node->g=node->myParent->g+1;
                    node->f=node->g+node->h;
                    openSet.emplace(node);
                }
                
            }
        }//end of for-loop
       
        if(openSet.size()==0)
        {
          //  cout<<"got here"<<endl;
            //return false;
            break;
        }
        float lowestF=10000;
        for( auto node: openSet)
        {
            if((node->f)<lowestF)
            {
                
                lowestF=currentNode->f;
                currentNode=node;
            }
        }
              closedSet.emplace(currentNode);
        openSet.erase(currentNode);

    }while(!(currentNode->gridPosition.x==StartNode.gridPosition.x&&currentNode->gridPosition.y==StartNode.gridPosition.y));
   
    PathStart=*currentNode;
    if(!(currentNode->gridPosition.x==StartNode.gridPosition.x&&currentNode->gridPosition.y==StartNode.gridPosition.y))
    {
        //cout<<"No path"<<endl;
        /*
        for(int i=0;i<9;i++)
        {
            for(int j =0;j<18;j++)
            {
                mNodes[i][j].myParent=nullptr;
            }
        }
         */
        openSet.clear();
        closedSet.clear();
        return false;
    }
    while(currentNode!=nullptr)
    {
        currentNode->myTile->GetMeshComponent()->SetColorIndex(currentNode->myTile->GetMeshComponent()->GetIndex()+4);
       currentNode=currentNode->myParent;
       
   }
    /*
    for(int i=0;i<9;i++)
    {
        for(int j =0;j<18;j++)
        {
            mNodes[i][j].myParent=nullptr;
        }
    }
     */
    openSet.clear();
    closedSet.clear();
    
    return true;
}


