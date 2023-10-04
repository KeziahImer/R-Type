/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

SceneManager::SceneManager(const std::map<std::string, json> &allData)
    : _allData(allData) {
  for (const auto &entry : _allData)
    _allScenes.push_back(entry.first);
}

SceneManager::~SceneManager() {}

void SceneManager::registerScene(std::string id) { _allScenes.push_back(id); }

void SceneManager::loadScene(std::string id) {
  bool isSceneExists = false;

  for (const std::string &sceneId : _allScenes) {
    if (sceneId == id) {
      isSceneExists = true;
      break;
    }
  }

  if (isSceneExists) {
    std::cout << "Load la scene " << id << std::endl;
    _actualScene = std::make_unique<Scene>(id, getSceneData(id));
    _actualSceneId = id;
  } else
    std::cerr << "La scène avec l'ID " << id << " n'existe pas." << std::endl;
}

json SceneManager::getSceneData(const std::string filename) {
  auto it = _allData.find(filename);

  if (it != _allData.end())
    return it->second;
  else {
    std::cerr << "Le fichier " << filename
              << " n'a pas été trouvé dans la map _allData." << std::endl;
    return nullptr;
  }
}

std::vector<std::string> SceneManager::getAllScenes() { return _allScenes; }

void SceneManager::unloadScene(std::string id) {
  _actualSceneId = "";
  _actualScene.get()->deleteEntities();
  _actualScene = nullptr;
}

std::string SceneManager::getActualScene() { return _actualSceneId; }

// Scene *SceneManager::getActualScene() {
//     return _actualScene.get();
// }

void SceneManager::snapshot() { return; }
