/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Scene
*/

#include "Scene.hpp"

Scene::Scene(std::string id, const json &data, GameEngine::Registry *registry) : _id(id), _data(data), _registry(registry) {
    
    ComponentFactory factory;
    std::cout << std::endl;

    for (const auto &entityData : data["entities"]) {
        std::string entityId = entityData["id"];
        GameEngine::EntityID entity = _registry->createEntity(entityId);

        for (const auto &componentData : entityData["components"]) {
            std::string componentId = "";
            std::string componentType = "";
            json componentDataJson;

            if (componentData.count("id"))
                componentId = componentData["id"];
            if (componentData.count("type"))
                componentType = componentData["type"];
            if (componentData.count("data"))
                componentDataJson = componentData["data"];
            
            std::shared_ptr<Component> component = factory.getComponent(componentType, componentId, componentDataJson);
            _registry->addComponent<Component>(entity, *component);
        }
    }
}

Scene::~Scene() {
    
}

void Scene::update() {
}

std::vector<GameEngine::EntityID> Scene::getEntities() {
    return _allEntities;
}

void Scene::deleteEntities() {
    // _allEntities.clear();
    // destroy les composants les data stockés de sfml -> sprite texture
}

std::string Scene::getId() {
    return _id;
}