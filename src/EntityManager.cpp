#include "./EntityManager.hpp"
#include "./Collision.hpp"
#include "./Components/ColliderComponent.hpp"
#include <iostream>

void EntityManager::ClearData()
{
    for (auto &entity : entities)
    {
        entity->Destroy();
    }
}
bool EntityManager::HasNoEntities() const
{
    return entities.size() == 0;
}
void EntityManager::Update(float deltaTime)
{
    for (auto &entity : entities)
    {
        entity->Update(deltaTime);
    }
    DestroyInactiveEntities();
}
void EntityManager::DestroyInactiveEntities()
{
    for (int i = 0; i < entities.size(); i++)
    {
        if (!entities[i]->IsActive())
        {
            entities.erase(entities.begin() + i);
        }
    }
}
void EntityManager::Render()
{

    for (int layerNumber = 0; layerNumber < NUM_LAYER; layerNumber++)
    {
        for (auto &entity : GetEntitiesByLayer(static_cast<LayerType>(layerNumber)))
        {
            entity->Render();
        }
    }
}
Entity &EntityManager::AddEntity(std::string entityName, LayerType layer)
{
    Entity *entity = new Entity(*this, entityName, layer);
    entities.emplace_back(entity);
    return *entity;
}
std::vector<Entity *> EntityManager::GetEntitiesByLayer(LayerType layer) const
{
    std::vector<Entity *> selectedEntities;
    for (auto &entity : entities)
    {
        if (entity->layer == layer)
        {
            selectedEntities.emplace_back(entity);
        }
    }
    return selectedEntities;
}
std::vector<Entity *> EntityManager::GetEntities() const
{
    return entities;
}
unsigned int EntityManager::GetEntityCount() const
{
    return entities.size();
}
void EntityManager::ListAllEntities() const
{
    unsigned int i = 0;
    for (auto &entity : entities)
    {
        std::cout << "Entity[" << i << "]" << entity->name << std::endl;
        entity->ListComponents();
        i++;
    }
}
// #include <iostream>
CollisionType EntityManager::CheckCollisions() const
{

    for (auto &thisEntity : entities)
    {
        if (thisEntity->HasComponent<ColliderComponent>())
        {
            ColliderComponent *thisCollider = thisEntity->GetComponent<ColliderComponent>();
            for (auto &thatEntity : entities)
            {
                if (thisEntity->name.compare(thatEntity->name) != 0 && thatEntity->HasComponent<ColliderComponent>())
                {
                    ColliderComponent *thatCollider = thatEntity->GetComponent<ColliderComponent>();
                    if (Collision::CheckRectangleCollison(thisCollider->collider, thatCollider->collider))
                    {
                        if (thisCollider->colliderTag.compare("PLAYER") == 0)
                        {
                            if (thatCollider->colliderTag.compare("ENEMY") == 0)
                            {
                                return PLAYER_ENEMY_COLLISION;
                            }
                            if (thatCollider->colliderTag.compare("PROJECTILE") == 0)
                            {
                                return PLAYER_PROJECTILE_COLLISION;
                            }
                            if (thatCollider->colliderTag.compare("LEVEL_COMPLETE") == 0)
                            {
                                return PLAYER_LEVEL_COMPLETE_COLLISION;
                            }
                        }
                        else if (
                            thisCollider->colliderTag.compare("ENEMY") == 0 &&
                            thatCollider->colliderTag.compare("FRIENDLY_PROJECTILE") == 0)
                        {
                            return ENEMY_PROJECTILE_COLLISION;
                        }
                    }
                }
            }
        }
    }
    return NO_COLLISION;
}

Entity *EntityManager::GetEntityByName(std::string entityName) const
{

    for (auto *entity : entities)
    {

        if (entity->name.compare(entityName) == 0)
        {
            return entity;
        };
    }
    return NULL;
}
