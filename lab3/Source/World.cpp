#include "World.h"
#include <iostream>
using namespace std;
World::World()
{

}

World::~World()
{

}

void World::AddActor(ActorPtr actor)
{
	mActors.emplace(actor);
}

Enemy* World::GetClosestEnemy(std::vector<Enemy*> enemiesInRange,Vector3 vec, float radius)
{
    Enemy* closestEnemy=nullptr;
    float shortestDis=10000;
    for(auto ene:enemiesInRange)
    {
        int xDif= fabs(ene->GetPosition().x-vec.x);
        int yDif= fabs(ene->GetPosition().y-vec.y);
        if(sqrt(xDif*xDif+yDif*yDif)<shortestDis)
        {
            closestEnemy=ene;
            shortestDis=sqrt(xDif*xDif+yDif*yDif);
        }

    }
    return closestEnemy;
}
std::vector<Enemy*> World::GetEnemiesInRange(Vector3 vec,float radius)
{
    std::vector<Enemy*> enemiesInRange;
    for(auto ene:mEnemy)
    {
        
        int xDif= fabs(ene->GetPosition().x-vec.x);
        int yDif= fabs(ene->GetPosition().y-vec.y);
        if(sqrt(xDif*xDif+yDif*yDif)<150)
        {
            enemiesInRange.push_back(ene);
        }
    }
    return enemiesInRange;
}

void World::Tick(float deltaTime)
{
	// Tick a copy of the actor pointers, in case any actor adds more actors
	auto actors = mActors;
	for (auto& actor : actors)
	{
		actor->TickInternal(deltaTime);
	}

	// Remove any actors that are dead
	auto iter = mActors.begin();
	while (iter != mActors.end())
	{
		if (!(*iter)->IsAlive())
		{
			(*iter)->EndPlay();
			iter = mActors.erase(iter);
		}
		else
		{
			++iter;
		}
	}
}

void World::RemoveAllActors()
{
	for (auto& actor : mActors)
	{
		actor->EndPlay();
	}
	mActors.clear();
}
