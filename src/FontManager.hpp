#ifndef FONTMANAGER_HPP
#define FONTMANAGER_HPP
#include "./Game.hpp"
class FontManager
{
public:
    static TTF_Font *LoadFont(const char *fileName, int fontSize);
    static void Draw(SDL_Texture *, SDL_Rect position);
};
#endif