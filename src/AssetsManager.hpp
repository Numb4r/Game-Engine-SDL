#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H
#include "./EntityManager.hpp"
#include <string>
#include <map>
#include "./TextureManager.hpp"
class AssetManager
{
private:
    EntityManager *manager;
    std::map<std::string, SDL_Texture *> textures;

public:
    AssetManager(EntityManager *manager);
    void ListTextures();
    ~AssetManager();
    void ClearData();
    void AddTexture(std::string textureId, const char *filePath);
    SDL_Texture *GetTexture(std::string textureId);
};

#endif