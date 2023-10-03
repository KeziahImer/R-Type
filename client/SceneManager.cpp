/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

SceneManager::SceneManager(const json &globalData) : _id(id), _globalData(globalData) {

}

SceneManager::~SceneManager() {
}

void SceneManager::registerScene(std::string id) {
    _allScenes.push_back(id);
}

void SceneManager::loadScene(std::string id) {
    
    bool isSceneExists = false;
 
    for (const std::string &sceneId : _allScenes) {
        if (sceneId == id) {
            sceneExists = true;
            break;
        }
    }

    if (isSceneExists) {
        _actualScene = std::make_unique<Scene>(id);
        _actualSceneId = id;
    } else
        std::cerr << "La scène avec l'ID " << id << " n'existe pas." << std::endl;
}

void SceneManager::unloadScene(std::string id) {
    _actualSceneId = "";
    _actualScene.get()->deleteEntities();
    _actualScene = nullptr;
}

Scene *SceneManager::getActualScene() {
    return _actualScene.get();
}

std::string SceneManager::getActualScene() {
    return _actualSceneId;
}

void SceneManager::snapshot() {

}
