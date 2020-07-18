#include <iostream>
#include "./AssetsManager.hpp"
#include "./Components/TransformComponents.hpp"

AssetManager::AssetManager(EntityManager *manager) : manager(manager) {}

void AssetManager::ClearData()
{
    textures.clear();
    fonts.clear();
}
void AssetManager::AddTexture(std::string textureId, const char *filePath)
{
    textures.emplace(textureId, TextureManager::LoadTexture(filePath));
}

SDL_Texture *AssetManager::GetTexture(std::string textureId)
{
    return textures[textureId];
}

void AssetManager::AddFont(std::string fontId, const char *filePath, int fontSize)
{
    fonts.emplace(fontId, FontManager::LoadFont(filePath, fontSize));
}
TTF_Font *AssetManager::GetFont(std::string fontId)
{
    return fonts[fontId];
}
void AssetManager::ListTextures()
{
    for (auto &texture : textures)
    {
        std::cout << texture.first << " : " << texture.second << std::endl;
    }
}
