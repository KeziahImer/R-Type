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
        SceneManager();
        ~SceneManager();
        registerScene(std::string id);
        loadScene(std::string id);
        unloadScene(std::string id);
        std::string getActualScene();
        Scene *getActualScene();
        snapshot();

    protected:
    private:
        json _globalData;
        std::vector<std::string> _allScenes;
        std::string _actualSceneId;
        std::unique_ptr<Scene> _actualScene;
        std::unique_ptr<Scene> _globalScene;
};
