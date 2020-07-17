#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H
#include "./EntityManager.hpp"
#include <string>
#include <map>
#include "./TextureManager.hpp"
#include "./FontManager.hpp"
#include <SDL2/SDL_ttf.h>
class AssetManager
{
private:
    EntityManager *manager;
    std::map<std::string, SDL_Texture *> textures;
    std::map<std::string, TTF_Font *> fonts;

public:
    AssetManager(EntityManager *manager);
    void ListTextures();
    ~AssetManager();
    void ClearData();

    void AddTexture(std::string textureId, const char *filePath);
    SDL_Texture *GetTexture(std::string textureId);

    void AddFont(std::string fontId, const char *filePath, int fontSize);
    TTF_Font *GetFont(std::string fontId);
};

#endif