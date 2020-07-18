#ifndef ENTITYMANAGER_HPP
#define ENTITYMANAGER_HPP
#include "./Entity.hpp"
#include "./Component.hpp"
#include "./Constants.h"
#include <vector>

class EntityManager
{
private:
    std::vector<Entity *> entities;

public:
    void ClearData();
    void Update(float deltaTime);
    void Render();
    bool HasNoEntities() const;
    Entity &AddEntity(std::string entityName, LayerType layer);
    std::vector<Entity *> GetEntities() const;
    std::vector<Entity *> GetEntitiesByLayer(LayerType layer) const;
    Entity *GetEntityByName(std::string entityName) const;
    unsigned int GetEntityCount() const;
    void ListAllEntities() const;
    void DestroyInactiveEntities();

    CollisionType CheckCollisions() const;
};

#endif