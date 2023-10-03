/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Scene
*/

#pragma once
    #include <vector>
    #include <memory>
    #include "Entity.hpp"

class Scene {
    public:
        Scene(std::string id, const json &globalData);
        ~Scene();
        void update();
        std::vector<std::shared_ptr<Entity>> getEntities();
        void deleteEntities();
        std::string getId();
        // getScreen();

    protected:
    private:
        std::string _id;
        json _data;
        std::vector<std::shared_ptr<Entity>> _allEntities;
};
