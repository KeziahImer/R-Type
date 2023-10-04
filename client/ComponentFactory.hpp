/*
** EPITECH PROJECT, 2023
** mirror
** File description:
** ComponentFactory
*/

#pragma once
#include "components/Components.hpp"
#include <functional>
#include "GameEngine/ECS.hpp"
#include <memory>
#include <nlohmann/json.hpp>
#include <variant>
using json = nlohmann::json;

using Component = std::variant<Position, Sprite, Velocity, Movable, Size, Shoot, Parallax>;

class ComponentFactory
{
public:
    ComponentFactory(GameEngine::Registry &registry);
    virtual ~ComponentFactory() = default;
    Component getComponent(const std::string &name, const GameEngine::EntityID &entity, const std::string &id, const json &data);
    void createAllComponents(const std::string &type, const json &data, const std::string &prefab = "", const std::string &id = "");

private:
    GameEngine::Registry &_registry;
    std::map<std::string, std::function<Component(const std::string &, const GameEngine::EntityID &entity, const json &)>> _components;
};
