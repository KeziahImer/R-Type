/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** SceneManager
*/

#pragma once
    #include <vector>
    #include <iostream>
    #include <memory>
    #include "Scene.hpp"

class SceneManager {
    public:
        SceneManager(const std::map<std::string, json> &allData, GameEngine::Registry *registry);
        ~SceneManager();
        void registerScene(std::string id);
        void loadScene(std::string id);
        void unloadScene(std::string id);
        std::string getActualScene();
        json getSceneData(const std::string filename);
        std::vector<std::string> getAllScenes();
        // Scene *getActualScene();
        void snapshot();

    protected:
    private:
        std::map<std::string, json> _allData;
        std::vector<std::string> _allScenes;
        std::string _actualSceneId;
        std::unique_ptr<Scene> _actualScene;
        std::unique_ptr<Scene> _globalScene;
        GameEngine::Registry *_registry;
};
