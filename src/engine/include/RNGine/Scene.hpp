/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype Scene
*/

#ifndef _RTYPE_ENGINE_SCENE_HPP_
#define _RTYPE_ENGINE_SCENE_HPP_

#include <any>
#include <functional>
#include <map>
#include <string>
#include <typeindex>
#include <vector>

#include "SparseArray.hpp"

namespace RNGine {
class Scene {
public:
  using Entity = std::size_t;
  using RemoveFun = std::function<Scene &(Scene &, Entity)>;

public:
  Scene() = default;
  Scene(Scene const &) = default;
  Scene(Scene &&) noexcept = default;
  ~Scene() = default;
  Scene &operator=(Scene const &) = default;
  Scene &operator=(Scene &&) noexcept = default;

  Entity CreateEntity();
  Entity CreateEntity(const std::string &);
  Entity GetEntity(const std::string &);
  void RemoveEntity(const std::string &);
  void RemoveEntity(Entity entity);

  template <typename Component> Scene &RegisterComponent() {
    auto type_id = std::type_index(typeid(Component));
    if (_components.find(type_id) == _components.end()) {
      _components[type_id] = std::make_any<RNGine::SparseArray<Component>>();
    }
    return *this;
  }

  template <typename Component> SparseArray<Component> &GetComponents() {
    auto type_id = std::type_index(typeid(Component));
    if (!_components[type_id].has_value()) {
      _components[type_id] = std::make_any<RNGine::SparseArray<Component>>();
    }
    return std::any_cast<SparseArray<Component> &>(_components[type_id]);
  }

  template <typename Component>
  Scene &AddComponent(Entity entity, Component const &component) {
    Scene &Scene = RegisterComponent<Component>();
    SparseArray<Component> &components = GetComponents<Component>();
    components.insert_at(entity, component);
    _removes[typeid(Component)] = &Scene::RemoveComponent<Component>;
    return *this;
  }

  template <typename Component>
  Scene &AddComponent(const std::string &name, Component const &component) {
    return AddComponent(GetEntity(name), component);
  }

  template <typename Component> Scene &RemoveComponent(Entity entity) {
    SparseArray<Component> &components = GetComponents<Component>();
    components.erase(entity);
    return *this;
  }

private:
  Entity _nextEntity = 0;
  std::map<std::string, Entity> _entities;

  std::map<std::type_index, std::any> _components;
  std::map<std::type_index, RemoveFun> _removes;
};
} // namespace RNGine

#endif