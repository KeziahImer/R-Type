/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Scene deifinition
*/

#ifndef _RNGINE_SCENE_HPP_
#define _RNGINE_SCENE_HPP_

#include <functional>
#include <iostream>
#include <memory>
#include <vector>

#include "./Registry.hpp"

namespace RNGine {
/**
 * @brief A Scene contain a registry and load it when it's created
 */
class Scene {
public:
  Scene() = default;
  Scene(const std::string &id) : _id(id) {}

  RNGine::Entity createEntity(std::string const &name) {
    if (_loaded) {
      return _registry.createEntity(name);
    } else {
      return _initial.createEntity(name);
    }
  }

  RNGine::Entity getEntity(std::string const &name) {
    if (_loaded) {
      return _registry.getEntity(name);
    } else {
      return _initial.getEntity(name);
    }
  }

  Scene &addBundle(RNGine::Registry::SystemBundle const &bundle) {
    if (_loaded) {
      _registry.addBundle(bundle);
    } else {
      _initial.addBundle(bundle);
    }
    return *this;
  }

  Scene &removeBundle(const size_t &index) {
    if (_loaded) {
      _registry.removeBundle(index);
    } else {
      _initial.removeBundle(index);
    }
    return *this;
  }

  template <typename Component>
  Scene &addComponent(RNGine::Entity entity, Component const &component) {
    if (_loaded) {
      _registry.addComponent(entity, component);
    } else {
      _initial.addComponent(entity, component);
    }
    return *this;
  }

  template <typename Component> Scene &removeComponent(RNGine::Entity entity) {
    if (_loaded) {
      _registry.removeComponent<Component>(entity);
    } else {
      _initial.removeComponent<Component>(entity);
    }
    return *this;
  }

  Scene &removeEntity(RNGine::Entity entity) {
    if (_loaded) {
      _registry.removeEntity(entity);
    } else {
      _initial.removeEntity(entity);
    }
    return *this;
  }

  Scene &load() {
    if (!_loaded) {
      _registry = _initial;
      _loaded = true;
    }
    return *this;
  }

  Scene &unload() {
    if (_loaded) {
      _registry = _initial;
      _loaded = false;
    }
    return *this;
  }

  Registry &update() {
    if (!_loaded)
      throw std::runtime_error("Scene not loaded.");
    if (!_registry.clock.checkFrame())
      return _registry;
    _registry.run();
    return _registry;
  }

  std::string getId() const { return _id; }

  void setId(std::string const &id) { _id = id; }

protected:
  std::string _id;
  RNGine::Registry _registry;
  RNGine::Registry _initial;
  bool _loaded = false;
};
}; // namespace RNGine

#endif