/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Scene
*/

#pragma once
    #include <vector>
    #include <memory>
    #include <nlohmann/json.hpp>
    #include <iostream>
    #include "GameEngine/ECS.hpp"
    #include "ComponentFactory.hpp"
    using json = nlohmann::json;

class Scene {
    public:
        Scene(std::string id, const json &data, GameEngine::Registry &registry);
        ~Scene();
        void update();
        std::vector<GameEngine::EntityID> getEntities();
        void deleteEntities();
        std::string getId();
        // getScreen();

    protected:
    private:
        std::string _id;
        json _data;
        std::vector<GameEngine::EntityID> _allEntities;
        GameEngine::Registry &_registry;
};
