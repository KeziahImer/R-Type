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
#include "./Scene.hpp"
#include "rngine/Renderer.hpp"

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

  void removeScene(size_t index) { _scenes.erase(_scenes.begin() + index); }

  void load(size_t index) {
    if (index == _loadedScene)
      return;

    _scenes[_loadedScene].unload();
    _scenes[index].load();
  }

  void update() {
    if (_scenes.size() > 0) {
      _renderer.render(_scenes[_loadedScene].update());
    }
  }

  RNGine::Scene &getActualScene() { return _scenes[_loadedScene]; }

private:
  size_t _loadedScene;
  std::vector<RNGine::Scene> _scenes;
  RNGine::Renderer _renderer = RNGine::Renderer(1920, 1080, "R-type");
};
}; // namespace RNGine

#endif