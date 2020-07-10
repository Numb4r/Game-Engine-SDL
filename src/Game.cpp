#include <iostream>
#include "../lib/glm/glm.hpp"
#include "./Game.hpp"
#include "./Constants.h"
#include "./Components/TransformComponents.hpp"
EntityManager manager;
SDL_Renderer *Game::renderer;
Game::Game()
{
    this->isRunning = false;
}

Game::~Game()
{
}

bool Game::IsRunning() const
{
    return isRunning;
}

void Game::Initialize(int width, int height)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Error initialing SDL." << std::endl;
        return;
    }
    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_BORDERLESS);
    if (!window)
    {
        std::cerr << "Error creating SDL window" << std::endl;
        return;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer)
    {
        std::cerr << "Error creating SDL renderer" << std::endl;
        return;
    }

    isRunning = true;
    LoadLevel(0);

    return;
}

void Game::LoadLevel(int levelNumber)
{
    Entity &newEntity(manager.AddEntity("projectile"));
    newEntity.AddComponent<TransformComponent>(0, 0, 20, 20, 32, 32, 1);
}
void Game::ProcessInput()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;

        break;
    case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE)
        {
            isRunning = false;
        }
        break;
    default:
        break;
    }
}
void Game::Update()
{
    int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - ticksLastFrame);
    if (timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME)
    {
        SDL_Delay(timeToWait);
    }
    //Delta time is the difference in ticks from last  frame converted to seconds
    float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;
    // Clamp deltaTime to a maximum value
    deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;
    //Sets the new ticks for the current frame to be used in the next pass
    ticksLastFrame = SDL_GetTicks();
    manager.Update(deltaTime);
}
void Game::Render()
{
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);

    if (manager.HasNoEntities())
        return;
    else
        manager.Render();
    SDL_RenderPresent(renderer);
}

void Game::Destroy()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}