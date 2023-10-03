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

using Component = std::variant<Position, Sprite, Velocity, Movable, Size>;

class ComponentFactory
{
public:
    ComponentFactory();
    virtual ~ComponentFactory() = default;
    Component getComponent(const std::string &name, const std::string &id, const json &data);

private:
    std::map<std::string, std::function<Component(const std::string&, const json&)>> _components;
};
