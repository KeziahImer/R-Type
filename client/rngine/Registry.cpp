#include "rngine/Registry.hpp"

RNGine::Entity RNGine::Registry::createEntity(std::string const &name) {
  EntityID id = nextEntityID_++;
  _entities[name] = id;
  return id;
}

RNGine::Entity RNGine::Registry::getEntityID(std::string const &name) {
  auto it = _entities.find(name);
  if (it != _entities.end()) {
    return it->second;
  }
  throw std::runtime_error("Entity not found in registry.");
}

RNGine::Registry &
RNGine::Registry::addBundle(RNGine::SystemBundle const &bundle) {
  _bundles.push_back(bundle);
  return *this;
}

RNGine::Registry &RNGine::Registry::removeBundle(const size_t &index) {
  _bundles.erase(_bundles.begin() + index);
  return *this;
}

RNGine::Registry &RNGine::Registry::run(void) {
  for (auto const &bundle : _bundles) {
    bundle.run(*this);
  }
  return *this;
}

template <typename Component>
RNGine::Registry &RNGine::Registry::registerComponent() {
  auto type_id = std::type_index(typeid(Component));
  if (components_.find(type_id) == components_.end()) {
    components_[type_id] = std::make_any<RNGine::SparseArray<Component>>();
  }
  return *this;
}

template <typename Component>
RNGine::SparseArray<Component> &RNGine::Registry::getComponents() {
  auto type_id = std::type_index(typeid(Component));
  return std::any_cast<RNGine::SparseArray<Component> &>(components_[type_id]);
}

template <typename Component>
RNGine::Registry &RNGine::Registry::addComponent(RNGine::EntityID entity,
                                                 Component const &component) {
  Registry &registry = registerComponent<Component>();
  SparseArray<Component> &components = registry.getComponents<Component>();
  components.insert_at(entity, component);
  _removes[typeid(Component)] = &RNGine::Registry::removeComponent<Component>;
  return *this;
}
