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
    using json = nlohmann::json;
    // #include "Entity.hpp"

class Scene {
    public:
        Scene(std::string id, const json &data);
        ~Scene();
        void update();
        // std::vector<std::shared_ptr<Entity>> getEntities();
        void deleteEntities();
        std::string getId();
        // getScreen();

    protected:
    private:
        std::string _id;
        json _data;
        // std::vector<std::shared_ptr<Entity>> _allEntities;
};
