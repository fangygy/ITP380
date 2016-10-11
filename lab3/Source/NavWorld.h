//
//  NavWorld.h
//  Game-mac
//
//  Created by Yizheng Fang on 10/7/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#ifndef __Game_mac__NavWorld__
#define __Game_mac__NavWorld__

#include <stdio.h>
#include "PathNode.h"

class NavWorld
{
public:
    NavWorld();
    ~NavWorld();
    //PathNode** getAllNode(){return mNodes;}
    PathNode& GetNode(int i, int j){return mNodes[i][j];}
    //std::vector<PathNode>* GetRowNodes(){return &mNodesRow;}
    PathNode& GetStartNode(){return StartNode;}
    PathNode& GetEndNode(){return EndNode;}
    PathNode& GetPath(){return PathStart;}
    bool TryFindPath();
private:
   // std::vector<PathNode> mNodesRow;
    //std::vector<std::vector<PathNode*>*> mNodes;
    PathNode mNodes[9][18];
    PathNode StartNode;
    PathNode EndNode;
    PathNode PathStart;
    
    std::unordered_set<PathNode*> closedSet;
    std::unordered_set<PathNode*> openSet;
};
#endif /* defined(__Game_mac__NavWorld__) */
