#ifndef _RNGINE_REGISTRY_HPP_
#define _RNGINE_REGISTRY_HPP_

#include <any>
#include <map>
#include <memory>
#include <typeindex>
#include <unordered_map>
#include <vector>

#include "./Entity.hpp"
#include "./Keys.hpp"
#include "./SparseArray.hpp"

namespace RNGine {

class Registry {
public:
  using System = std::function<void(Registry &)>;
  using SystemBundle = std::vector<System>;

  RNGine::Entity createEntity(std::string const &name) {
    RNGine::Entity id = nextEntityID_++;
    _entities[name] = id;
    return id;
  }

  RNGine::Entity getEntity(std::string const &name) {
    auto it = _entities.find(name);
    if (it != _entities.end()) {
      return it->second;
    }
    throw std::runtime_error("Entity not found in registry.");
  }

  Registry &addBundle(SystemBundle const &bundle) {
    _bundles.push_back(bundle);
    return *this;
  }

  Registry &removeBundle(const size_t &index) {
    _bundles.erase(_bundles.begin() + index);
    return *this;
  }

  Registry &run(void) {
    for (auto &bundle : _bundles) {
      for (auto &system : bundle) {
        system(*this);
      }
    }
    return *this;
  }

  template <typename Component> Registry &registerComponent() {
    auto type_id = std::type_index(typeid(Component));
    if (components_.find(type_id) == components_.end()) {
      components_[type_id] = std::make_any<RNGine::SparseArray<Component>>();
    }
    return *this;
  }

  template <typename Component> SparseArray<Component> &getComponents() {
    auto type_id = std::type_index(typeid(Component));
    return std::any_cast<SparseArray<Component> &>(components_[type_id]);
  }

  template <typename Component>
  Registry &addComponent(RNGine::Entity entity, Component const &component) {
    Registry &registry = registerComponent<Component>();
    SparseArray<Component> &components = registry.getComponents<Component>();
    components.insert_at(entity, component);
    _removes[typeid(Component)] = &Registry::removeComponent<Component>;
    return *this;
  }

  template <typename Component>
  Registry &removeComponent(RNGine::Entity entity) {
    SparseArray<Component> &components = getComponents<Component>();
    components.erase(entity);
    return *this;
  }

  void removeEntity(RNGine::Entity entity) {
    for (auto remove : _removes) {
      remove.second(*this, entity);
    }
  }

  void setInputs(std::map<enum RNGine::Key, bool> &inputsMap) {
    _inputsMap = inputsMap;
  }

  std::map<enum RNGine::Key, bool> getInputs() { return _inputsMap; }

private:
  std::unordered_map<std::type_index, std::any> components_;
  std::unordered_map<std::type_index, std::function<Registry &(
                                          Registry &, RNGine::Entity entity)>>
      _removes;
  std::map<std::string, RNGine::Entity> _entities;
  size_t nextEntityID_ = 0;
  std::vector<SystemBundle> _bundles;
  std::map<enum RNGine::Key, bool> _inputsMap;
};
}; // namespace RNGine

#endif