/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game implementation
*/

#include "RNGine/Core.hpp"

#include <chrono>
#include <iostream>

RNGine::Core::Core() {
  currentTime = GetNow();
  nextUpdate = currentTime;
}

bool RNGine::Core::Update() {
  currentTime = GetNow();
  if (currentTime < nextUpdate)
    return false;
  deltaTime = currentTime - lastUpdate;
  lastUpdate = currentTime;
  nextUpdate = currentTime + (1.0 / (float)targetFPS);
  RunSystems();
  return true;
}

RNGine::Core::Time RNGine::Core::GetNow() {
  auto now = std::chrono::steady_clock::now();
  std::chrono::duration<double> time_span =
      std::chrono::duration_cast<std::chrono::duration<double>>(
          now.time_since_epoch());
  return time_span.count();
}

void RNGine::Core::AddSystem(const std::string &name, System fun) {
  _systems[name] = fun;
}
void RNGine::Core::RemoveSystem(const std::string &name) {
  _systems.erase(name);
}
void RNGine::Core::RunSystems() {
  for (auto &system : _systems) {
    system.second(*this);
  }
}

void RNGine::Core::AddScene(const std::string &name, const Scene &scene) {
  _scenes[name] = scene;
}

void RNGine::Core::RemoveScene(const std::string &name) { _scenes.erase(name); }

void RNGine::Core::SetActualScene(const std::string &name) {
  _actualScene = name;
}

RNGine::Scene &RNGine::Core::GetScene(const std::string &name) {
  return _scenes[name];
}

const RNGine::Scene &RNGine::Core::GetScene(const std::string &name) const {
  return _scenes.at(name);
}

RNGine::Scene &RNGine::Core::GetActualScene() { return _scenes[_actualScene]; }

const RNGine::Scene &RNGine::Core::GetActualScene() const {
  return _scenes.at(_actualScene);
}

std::string RNGine::Core::GetActualSceneName() const { return _actualScene; }
