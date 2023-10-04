/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Scene
*/

#include "Scene.hpp"

Scene::Scene(std::string id, const json &data) : _id(id), _data(data) {

  std::cout << std::endl;

  for (const auto &entityData : data["entities"]) {
    std::string entityId = entityData["id"];
    // Entity entity(entityId);
    std::cout << "Creation de l'entity : " << entityId << "\n" << std::endl;

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
      // entity.addComponent(componentId, componentDataJson);
      std::cout << "   Creation du composant : " << componentId << " de type "
                << componentType << std::endl;
      std::cout << "     " << componentDataJson << std::endl;
    }

    // _allEntities.push_back(entity);
    std::cout << "\n-----------" << std::endl;
  }
}

Scene::~Scene() {}

void Scene::update() {}

std::vector<GameEngine::EntityID> Scene::getEntities() { return _allEntities; }

void Scene::deleteEntities() {
  // _allEntities.clear();
  // destroy les composants les data stockés de sfml -> sprite texture
}

std::string Scene::getId() { return _id; }
