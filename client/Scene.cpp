/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Scene
*/

#include "Scene.hpp"

Scene::Scene(std::string id, const json &data, GameEngine::Registry &registry) : _id(id), _data(data), _registry(registry)
{

    ComponentFactory factory;
    std::cout << std::endl;

    for (const auto &entityData : data["entities"]) {
        std::string entityId = entityData["id"];
        GameEngine::EntityID entity = _registry.createEntity(entityId);

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

            if (componentType == "sprite") {
                auto spriteComponent = factory.getComponent("sprite", componentId, componentDataJson);
                if (std::holds_alternative<Sprite>(spriteComponent)) {
                Sprite sprite = std::get<Sprite>(spriteComponent);
                _registry.addComponent<Sprite>(entity, sprite);
            }}

            if (componentType == "position") {
                auto positionComponent = factory.getComponent("position", componentId, componentDataJson);
                if (std::holds_alternative<Position>(positionComponent)) {
                Position position = std::get<Position>(positionComponent);
                _registry.addComponent<Position>(entity, position);
            }}

            if (componentType == "size") {
                auto sizeComponent = factory.getComponent("size", componentId, componentDataJson);
                if (std::holds_alternative<Size>(sizeComponent)) {
                Size size = std::get<Size>(sizeComponent);
                _registry.addComponent<Size>(entity, size);
            }}

            if (componentType == "velocity") {
                auto velocityComponent = factory.getComponent("velocity", componentId, componentDataJson);
                if (std::holds_alternative<Velocity>(velocityComponent)) {
                Velocity velocity = std::get<Velocity>(velocityComponent);
                _registry.addComponent<Velocity>(entity, velocity);
            }}

            if (componentType == "movable") {
                auto movableComponent = factory.getComponent("movable", componentId, componentDataJson);
                if (std::holds_alternative<Movable>(movableComponent)) {
                Movable movable = std::get<Movable>(movableComponent);
                _registry.addComponent<Movable>(entity, movable);
            }}

        }
    }
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