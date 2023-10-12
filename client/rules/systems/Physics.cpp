#include "rules/systems/Physics.hpp"

RNGine::Registry::System velocitySystem = [](RNGine::Registry &registry) {
  std::cout << "Velocity System Run" << std::endl;
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
  std::cout << "Velocity System Finished" << std::endl;
};

RNGine::Registry::System MovableSystem = [](RNGine::Registry &registry) {
  std::cout << "Movable System Run" << std::endl;
  RNGine::SparseArray<RNGine::components::Movable> &Movables =
      registry.getComponents<RNGine::components::Movable>();
  std::cout << "Movable Components getted" << std::endl;
  RNGine::SparseArray<RNGine::components::Velocity> &Velocities =
      registry.getComponents<RNGine::components::Velocity>();
  std::cout << "Components getted" << std::endl;
  std::map<enum RNGine::Key, bool> inputs = registry.inputs;
  std::cout << "Inputs getted" << std::endl;
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
  std::cout << "Movable System Finished" << std::endl;
};

namespace Rtype {
RNGine::Registry::SystemBundle physicsSystems = {velocitySystem, MovableSystem};
}
