/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype scene implementation
*/

#include "RNGine/Scene.hpp"
#include <iostream>

RNGine::Scene::Entity RNGine::Scene::CreateEntity(const std::string &name) {
  auto id = _nextEntity++;
  _entities[name] = id;
  _names[id] = name;
  return id;
}

RNGine::Scene::Entity RNGine::Scene::CreateEntity() {
  auto id = _nextEntity++;
  return id;
}

RNGine::Scene::Entity RNGine::Scene::GetEntity(const std::string &name) {
  return _entities[name];
}

std::string RNGine::Scene::GetEntityName(Entity entity) {
  return _names[entity];
}

void RNGine::Scene::RemoveEntity(Entity entity) {
  for (auto &remove : _removes) {
    remove.second(*this, entity);
  }
}

void RNGine::Scene::RemoveEntity(const std::string &name) {
  RemoveEntity(_entities[name]);
}
