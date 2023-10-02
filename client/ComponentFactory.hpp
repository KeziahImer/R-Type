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
using json = nlohmann::json;

class ComponentFactory {
    public:
        ComponentFactory();
        virtual ~ComponentFactory() = default;
        std::shared_ptr<Component> getComponent(std::string name, std::string id, const json &componentData);


    private:
        std::map<std::string, std::function<std::shared_ptr<Component>(std::string, const json&)>> _components;

};
