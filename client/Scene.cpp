/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Scene
*/

#include "Scene.hpp"

Scene::Scene(std::string id, const json &data, GameEngine::Registry &registry) : _id(id), _data(data), _registry(registry)
{

    ComponentFactory factory(_registry);
    Systems systems;

    std::function<void(GameEngine::Registry &)> checkMovable = std::bind(&Systems::checkMovable, &systems, std::placeholders::_1);
    std::function<void(GameEngine::Registry &)> checkVelocity = std::bind(&Systems::checkVelocity, &systems, std::placeholders::_1);
    std::function<void(GameEngine::Registry &)> updateParallax = std::bind(&Systems::updateParallax, &systems, std::placeholders::_1);
    std::function<void(GameEngine::Registry &)> destroyOutScreenEntity = std::bind(&Systems::destroyOutScreenEntity, &systems, std::placeholders::_1);
    std::function<void(GameEngine::Registry &)> checkShoot = std::bind(&Systems::checkShoot, &systems, std::placeholders::_1);

    factory.createAllComponents("scene", data);

    registry.registerFunction(checkMovable);
    registry.registerFunction(checkVelocity);
    registry.registerFunction(updateParallax);
    registry.registerFunction(destroyOutScreenEntity);
    registry.registerFunction(checkShoot);
}

Scene::~Scene()
{
}

void Scene::update()
{
}

std::vector<GameEngine::EntityID> Scene::getEntities()
{
    return _allEntities;
}

void Scene::deleteEntities()
{
    // _allEntities.clear();
    // destroy les composants les data stockés de sfml -> sprite texture
}

std::string Scene::getId()
{
    return _id;
}
