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
#include "SFML/Window/Event.hpp"
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
    std::cout << "try unload " << std::endl;
    _scenes[_loadedScene].unload();
    std::cout << "after unload " << std::endl;
    _scenes[index].load();
    _loadedScene = index;
    std::cout << "after load " << std::endl;
  }

  void setInputs() {
    sf::Event event;
    while (_renderer.getWindow().pollEvent(event)) {
      switch (event.type) {
      case sf::Event::KeyPressed:
        _keybinds[static_cast<enum RNGine::Key>(event.key.code)] = true;
        break;
      case sf::Event::KeyReleased:
        _keybinds[static_cast<enum RNGine::Key>(event.key.code)] = false;
        break;
      case sf::Event::MouseButtonPressed:
        if (event.mouseButton.button == sf::Mouse::Left) {
          _mouseBinds.push_back(
              std::make_pair(event.mouseButton.x, event.mouseButton.y));
        }
        break;
      case sf::Event::Closed:
        _renderer.getWindow().close();
        _running = false;
        break;
      default:
        break;
      }
    }
  }

  bool update() {
    if (_scenes.size() > 0) {
      std::cout << "run :" << _loadedScene << std::endl;
      setInputs();
      _renderer.render(_scenes[_loadedScene].update(_keybinds, _mouseBinds));
    }
    return _running;
  }

  RNGine::Scene &getActualScene() { return _scenes[_loadedScene]; }

private:
  bool _running = true;
  size_t _loadedScene = 0;
  std::vector<RNGine::Scene> _scenes;
  RNGine::Renderer _renderer = RNGine::Renderer(1920, 1080, "R-type");
  std::map<enum RNGine::Key, bool> _keybinds;
  std::vector<std::pair<int, int>> _mouseBinds;
};
}; // namespace RNGine

#endif