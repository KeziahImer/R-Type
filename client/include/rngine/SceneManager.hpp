/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** SceneManager deifinition
*/

#ifndef _RNGINE_SCENE_MANAGER_HPP_
#define _RNGINE_SCENE_MANAGER_HPP_

#include <functional>
#include <iostream>
#include <memory>
#include <vector>

#include "./Registry.hpp"

namespace RNGine {
/**
 * @brief A SceneManager contain all the scenes and let you switch between them
 */
class SceneManager {
public:
  size_t addScene(RNGine::Scene const &scene) {
    size_t index = _scenes.size();
    _scenes.push_back(scene);
    return index;
  }

  void removeScene(size_t index) {
    _scenes.erase(_scenes.begin() + index);
    return *this;
  }

  void load(size_t index) {
    if (index == _loadedScene)
      return;

    _scenes[_loadedScene].unload();
    _scenes[index].load();
  }

  void update() {
    permanentScene.update();
    _scenes[_loadedScene].update();
  }

  void getActualScene() { return _scenes[_loadedScene]; }

public:
  RNGine::Scene permanentScene;

private:
  size_t _loadedScene;
  std::vector<RNGine::Scene> _scenes;
};
}; // namespace RNGine

#endif