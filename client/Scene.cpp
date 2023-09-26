/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Scene
*/

#include "Scene.hpp"

Scene::Scene(std::string id, const json &data) : _id(id), _data(data) {

}

Scene::~Scene() {
    
}

void Scene::update() {
}

std::vector<std::shared_ptr<Entity>> Scene::getEntities() {
    return _allEntities;
}

void Scene::deleteEntities() {
    _allEntities.clear();
    // destroy les composants les data stockés de sfml -> sprite texture
}

std::string Scene::getId() {
    return _id;
}