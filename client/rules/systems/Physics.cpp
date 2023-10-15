#include "rules/systems/Physics.hpp"
#include "rngine/Registry.hpp"
#include "rngine/components/InfiniteScroll.hpp"
#include "rngine/components/Position.hpp"

RNGine::Registry::System velocitySystem = [](RNGine::Registry &registry) {
  RNGine::SparseArray<RNGine::components::Velocity> &Velocities =
      registry.getComponents<RNGine::components::Velocity>();
  RNGine::SparseArray<RNGine::components::Position> &Positions =
      registry.getComponents<RNGine::components::Position>();

  float deltaTime = registry.clock.getDeltaTimeMilliseconds();
  for (size_t i = 0; i < Velocities.size(); i++) {
    if (!Positions[i].has_value() || !Velocities[i].has_value())
      continue;
    Positions[i]->x = Positions[i]->x + (Velocities[i]->x * deltaTime);
    Positions[i]->y = Positions[i]->y + (Velocities[i]->y * deltaTime);
  }
};

RNGine::Registry::System MovableSystem = [](RNGine::Registry &registry) {
  RNGine::SparseArray<RNGine::components::Movable> &Movables =
      registry.getComponents<RNGine::components::Movable>();
  RNGine::SparseArray<RNGine::components::Velocity> &Velocities =
      registry.getComponents<RNGine::components::Velocity>();
  std::map<enum RNGine::Key, bool> inputs = registry.inputs;
  for (size_t i = 0; i < Movables.size(); i++) {
    if (!Movables[i].has_value() || !Velocities[i].has_value())
      continue;
    Velocities[i]->x = 0;
    Velocities[i]->y = 0;
    for (auto inputPress : inputs) {
      for (auto inputRequire : Movables[i]->keybinds) {
        if ((inputPress.first == inputRequire.first) && inputPress.second) {
          Velocities[i]->x += inputRequire.second.first;
          Velocities[i]->y += inputRequire.second.second;
        }
      }
    }
  }
};

RNGine::Registry::System SelfDestroy = [](RNGine::Registry &registry) {
  RNGine::SparseArray<RNGine::components::Selfdestroy> &SelfDestroys =
      registry.getComponents<RNGine::components::Selfdestroy>();
  RNGine::SparseArray<RNGine::components::Position> &Positions =
      registry.getComponents<RNGine::components::Position>();
  std::map<enum RNGine::Key, bool> inputs = registry.inputs;
  for (size_t i = 0; i < SelfDestroys.size(); i++) {
    if (!SelfDestroys[i].has_value() || !Positions[i].has_value())
      continue;
    if (Positions[i]->x > SelfDestroys[i]->MaxX ||
        Positions[i]->y > SelfDestroys[i]->MaxY ||
        Positions[i]->x < SelfDestroys[i]->MinX ||
        Positions[i]->y < SelfDestroys[i]->MinY) {
      registry.removeEntity(i);
    }
  }
};

RNGine::Registry::System InfiniteScrollSystem = [](RNGine::Registry &registry) {
  RNGine::SparseArray<RNGine::components::InfiniteScroll> &InfiniteScrolls =
      registry.getComponents<RNGine::components::InfiniteScroll>();
  RNGine::SparseArray<RNGine::components::Position> &Positions =
      registry.getComponents<RNGine::components::Position>();
  for (size_t i = 0; i < InfiniteScrolls.size(); i++) {
    if (!InfiniteScrolls[i].has_value() || !Positions[i].has_value())
      continue;
    if (Positions[i]->x <= InfiniteScrolls[i]->switchValue) {
      Positions[i]->x = InfiniteScrolls[i]->respawnValue;
    }
  }
};

namespace Rtype {
RNGine::Registry::SystemBundle physicsSystems = {
    velocitySystem, MovableSystem, SelfDestroy, InfiniteScrollSystem};
}
