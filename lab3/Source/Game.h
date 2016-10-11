// Game.h
// Contains the core game functionality
// such as the game loop

#pragma once
#include "Renderer.h"
#include "FrameTimer.h"
#include "World.h"
#include "AssetCache.h"
#include "PhysWorld.h"
// include "Ship.h"
#include "InputManager.h"
#include "GameTimers.h"
#include "GameMode.h"
#include "NavWorld.h"
class Game
{
public:
	Game();
	~Game();
	bool Init();
	void RunLoop();
	void Quit();
    
    GameModePtr GetGameMode(){return mGameMode;}
	Renderer& GetRenderer() { return mRenderer; }
	World& GetWorld() { return mWorld; }
	AssetCache& GetAssetCache() { return mAssetCache; }
	PhysWorld& GetPhysWorld() { return mPhysWorld; }
    NavWorld& GetNavWorld(){return mNavWorld;}
    InputManager& GetInput() { return mInput;}
    GameTimerManager& GetGameTimers() { return mTime;}
    void AddInputMappings();
private:
	void StartGame();
	
	void ProcessInput();
	void HandleKeyPressed(int key);
	void HandleKeyReleased(int key);

	void Tick();
	void GenerateOutput();
   // ShipPtr mShip;
	Renderer mRenderer;
    GameModePtr mGameMode;
	FrameTimer mTimer;
	World mWorld;
	AssetCache mAssetCache;
    NavWorld mNavWorld;
    PhysWorld mPhysWorld;
    InputManager mInput;
    GameTimerManager mTime;
	bool mShouldQuit;
};
