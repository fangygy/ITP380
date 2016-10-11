// World.h
// All actors in the game world should either
// directly or indirectly (by parent) be
// controlled by World

#pragma once
#include <memory>
#include <unordered_set>
#include "Actor.h"
#include "Enemy.h"

class World
{
public:
	World();
	~World();

	void AddActor(ActorPtr actor);

	void Tick(float deltaTime);
    Enemy* GetClosestEnemy(std::vector<Enemy*> enemiesInRange,Vector3 vec, float radius);
    std::unordered_set<Enemy*>* GetEnemy(){return &mEnemy;}
    std::vector<Enemy*> GetEnemiesInRange(Vector3 vec,float radius);
	void RemoveAllActors();
private:
	std::unordered_set<ActorPtr> mActors;
    std::unordered_set<Enemy*> mEnemy;
};
    