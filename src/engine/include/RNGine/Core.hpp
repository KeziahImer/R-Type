/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype engine
*/

#ifndef _RTYPE_ENGINE_CORE_HPP_
#define _RTYPE_ENGINE_CORE_HPP_

#include <functional>
#include <map>
#include <string>

#include "Scene.hpp"

namespace RNGine {
class Core {
public:
  using Time = double;
  using System = std::function<void(Core &)>;

public:
  Core();

  bool Update();
  Time GetNow();

  void AddSystem(const std::string &name, System fun);
  void RemoveSystem(const std::string &name);
  void RunSystems();

  void AddScene(const std::string &name, const Scene &scene);
  void RemoveScene(const std::string &name);
  void SetActualScene(const std::string &name);
  Scene &GetScene(const std::string &name);
  const Scene &GetScene(const std::string &name) const;
  Scene &GetActualScene();
  const Scene &GetActualScene() const;
  std::string GetActualSceneName() const;

  Time currentTime = 0;
  Time nextUpdate = 0;
  Time lastUpdate = 0;
  Time deltaTime = 0;
  int targetFPS = 60;

private:
  std::map<std::string, System> _systems;
  std::map<std::string, Scene> _scenes;
  std::string _actualScene;
};
} // namespace RNGine

#endif