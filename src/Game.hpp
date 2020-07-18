#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "./Entity.hpp"
#include "./EntityManager.hpp"
#include "./Component.hpp"
#include "../lib/lua/sol.hpp"

class AssetManager;
class Game
{
private:
    bool isRunning;
    SDL_Window *window;

public:
    static SDL_Renderer *renderer;
    static AssetManager *assetManager;
    static SDL_Event event;
    static SDL_Rect camera;
    void HandleCameraMovement();
    void CheckCollisions();
    void LoadLevel(int levelNumber);
    bool IsRunning() const;
    int ticksLastFrame;
    void Initialize(int width, int height);
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();
    void ProcessGameOver();
    void ProcessNextLevel(int levelNumber);
    Game();
    ~Game();
};
#endif