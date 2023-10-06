#ifndef _RNGINE_REGISTRY_HPP_
#define _RNGINE_REGISTRY_HPP_

#include "rngine/types/Entity.hpp"
#include "rngine/types/SparseArray.hpp"
#include "rngine/types/SystemBundle.hpp"

namespace RNGine {
class Registry {
public:
  RNGine::Entity createEntity(std::string const &name) {
    EntityID id = nextEntityID_++;
    _entities[name] = id;
    return id;
  }

  RNGine::Entity getEntityID(std::string const &name) {
    auto it = _entities.find(name);
    if (it != _entities.end()) {
      return it->second;
    }
    throw std::runtime_error("Entity not found in registry.");
  }

  Registry &addBundle(RNGine::SystemBundle const &bundle) {
    _bundles.push_back(bundle);
    return *this;
  }

  Registry &removeBundle(const size_t &index) {
    _bundles.erase(_bundles.begin() + index);
    return *this;
  }

  Registry &run(void) {
    for (auto const &bundle : _bundles) {
      bundle.run(*this);
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
  Registry &addComponent(EntityID entity, Component const &component) {
    Registry &registry = registerComponent<Component>();
    SparseArray<Component> &components = registry.getComponents<Component>();
    components.insert_at(entity, component);
    _removes[typeid(Component)] = &Registry::removeComponent<Component>;
    return *this;
  }

  template <typename Component> Registry &removeComponent(EntityID entity) {
    SparseArray<Component> &components = getComponents<Component>();
    components.erase(entity);
    return *this;
  }

  void removeEntity(EntityID entity) {
    for (auto remove : _removes) {
      remove.second(*this, entity);
    }
  }

  void setInputs(std::map<enum sf::Keyboard::Key, bool> &inputsMap) {
    _inputsMap = inputsMap;
  }

  std::map<enum sf::Keyboard::Key, bool> getInputs() { return _inputsMap; }

public:
  Clock clock = Clock(60);

private:
  std::unordered_map<std::type_index, std::any> components_;
  std::unordered_map<std::type_index,
                     std::function<Registry &(Registry &, EntityID entity)>>
      _removes;
  std::map<std::string, EntityID> _entities;
  size_t nextEntityID_ = 0;
  std::vector<RNGine::SystemBundle> _bundles;
  std::map<enum sf::Keyboard::Key, bool> _inputsMap;
};
}; // namespace RNGine

#endif