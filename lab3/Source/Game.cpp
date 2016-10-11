#include "Game.h"
#include <SDL/SDL.h>
#include "Texture.h"
#include "Random.h"
#include "SpriteComponent.h"
//#include "Asteroid.h"
#include <SDL/SDL_mixer.h>
#include "FontComponent.h"



Game::Game()
	:mRenderer(*this)
	,mAssetCache(*this, "Assets/")
	,mShouldQuit(false)
{
    
}

Game::~Game()
{
	mAssetCache.Clear();
	mWorld.RemoveAllActors();
    
   //mShip=nullptr;
    Mix_CloseAudio();
    TTF_Quit();
	SDL_Quit();
}

void Game::AddInputMappings()
{
    mInput.AddActionMapping("Quit", SDLK_ESCAPE);
    mInput.AddActionMapping("Fire", SDLK_SPACE);
    mInput.AddActionMapping("SpawnFrost",SDLK_1);
    mInput.AddActionMapping("SpawnCannon",SDLK_2);
    mInput.BindAction("Quit", IE_Released, this, &Game::Quit);
    mInput.AddAxisMapping("Rotate",'a','d');
    mInput.AddAxisMapping("Move",'w','s');
    mInput.AddActionMapping("Select",SDL_BUTTON_LEFT);
   
    
}
bool Game::Init()
{
	// Initialize SDL
    
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		SDL_Log("Failed to initialize SDL.");
		return false;
	}

	// Initialize Renderer
	if (!mRenderer.Init(1024, 768))
	{
		SDL_Log("Failed to initialize renderer.");
		return false;
	}
    if( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048)==0)
    {
        printf("sound library initiated\n");
    }
    else
    {
        SDL_Log("Error: Cannot initiate sound library\n");
        return false;
    }
    TTF_Init();
	// Initialize RNG
	Random::Init();

	// Start frame timer
	mTimer.Start();
    AddInputMappings();
	// Run any code at game start
	StartGame();

	return true;
}

void Game::RunLoop()
{
	// TODO
    while(!mShouldQuit)
    {
        ProcessInput();
        Tick();
        GenerateOutput();
    }
}

void Game::Quit()
{
	// TODO
    mShouldQuit =true;
}

void Game::StartGame()
{
	// TODO
    // Testing SpriteComponents
    //const int NUM_ASTEROIDS = 10;
    Vector3 minVec(-512.0f, -384.0f, 0.0f);
    Vector3 maxVec(512.f, 384.f, 0.0f);
    mGameMode=GameMode::Spawn(*this);
//    auto test=HUD::Spawn(*this);
    //gameModeInstance->BeginPlay();
   // for (int i = 0; i < NUM_ASTEROIDS; i++)
  //  {
     //   auto ast = Asteroid::Spawn(*this);
    //    ast->SetPosition(Random::GetVector(minVec, maxVec));
    //    ast->SetScale(0.75f);
   // }
    //mShip = Ship::Spawn(*this);
   // mShip->SetPosition(Vector3(-10.0f, -10.0f, 0.0f));
    //mShip->SetRotation(Math::PiOver2);
    //mShip->SetScale(0.5f);}
}
void Game::ProcessInput()
{
	// TODO
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                mShouldQuit = true;
                break;
            
            case SDL_MOUSEBUTTONDOWN:
                if (event.key.repeat == 0)
                {
                    HandleKeyPressed(event.button.button);
                    /*
                     if(event.key.keysym.sym==SDLK_w)
                     {
                     mShip->GetMoveComponent()->AddToLinearAxis(1.0f);
                     }
                     if(event.key.keysym.sym==SDLK_s)
                     {
                     mShip->GetMoveComponent()->AddToLinearAxis(-1.0f);
                     }
                     if(event.key.keysym.sym==SDLK_a)
                     {
                     mShip->GetMoveComponent()->AddToAngularAxis(1.0f);
                     }
                     if(event.key.keysym.sym==SDLK_d)
                     {
                     mShip->GetMoveComponent()->AddToAngularAxis(-1.0f);
                     }
                     if(event.key.keysym.sym==SDLK_SPACE)
                     {
                     mShip->FireMissle();
                     }
                     
                     */
                    
                }
                break;
         
                      case SDL_KEYDOWN:
                if (event.key.repeat == 0)
                {
                    HandleKeyPressed(event.key.keysym.sym);
                    /*
                     if(event.key.keysym.sym==SDLK_w)
                     {
                     mShip->GetMoveComponent()->AddToLinearAxis(1.0f);
                     }
                     if(event.key.keysym.sym==SDLK_s)
                     {
                     mShip->GetMoveComponent()->AddToLinearAxis(-1.0f);
                     }
                     if(event.key.keysym.sym==SDLK_a)
                     {
                     mShip->GetMoveComponent()->AddToAngularAxis(1.0f);
                     }
                     if(event.key.keysym.sym==SDLK_d)
                     {
                     mShip->GetMoveComponent()->AddToAngularAxis(-1.0f);
                     }
                     if(event.key.keysym.sym==SDLK_SPACE)
                     {
                     mShip->FireMissle();
                     }
                     
                     */
                    
                }
                break;

            case SDL_KEYUP:
                HandleKeyReleased(event.key.keysym.sym);
                /*
                if(event.key.keysym.sym==SDLK_w)
                {
                    mShip->GetMoveComponent()->AddToLinearAxis(-1.0f);
                }
                if(event.key.keysym.sym==SDLK_s)
                {
                    mShip->GetMoveComponent()->AddToLinearAxis(1.0f);
                }
                if(event.key.keysym.sym==SDLK_a)
                {
                    mShip->GetMoveComponent()->AddToAngularAxis(-1.0f);
                }
                if(event.key.keysym.sym==SDLK_d)
                {
                    mShip->GetMoveComponent()->AddToAngularAxis(1.0f);
                }
                 */

                break;
            default:
                break;
        }
    }
}

void Game::HandleKeyPressed(int key)
{
    mInput.HandleKeyPressed(key);
	// TODO
}

void Game::HandleKeyReleased(int key)
{
    mInput.HandleKeyReleased(key);
	// TODO
}

void Game::Tick()
{
	// TODO
    float timeLapsed= mTimer.GetFrameTime(0.016666f);
    mTime.Tick(timeLapsed);
    mWorld.Tick(timeLapsed);
    mPhysWorld.Tick(timeLapsed);
}

void Game::GenerateOutput()
{
	// TODO
    mRenderer.RenderFrame();
    
}
