#ifndef COLLISION_HPP
#define COLLISION_HPP
#include <SDL2/SDL.h>
class Collision
{

public:
    static bool CheckRectangleCollison(const SDL_Rect &rectangleA, const SDL_Rect &rectangleB);
};

#endif