//
//  PathNode.h
//  Game-mac
//
//  Created by Yizheng Fang on 10/7/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#ifndef Game_mac_PathNode_h
#define Game_mac_PathNode_h
#include "Tile.h"
struct PathNode
{
    std::vector<PathNode*>  adjacentNodes;
    TilePtr myTile;
    Vector2 gridPosition;
    PathNode* myParent;
    float f;
    float g;
    float h;
    bool isBlocked;
};

#endif
