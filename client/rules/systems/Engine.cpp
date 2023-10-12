#include "rules/systems/Engine.hpp"

RNGine::Registry::System UpdateScore = [](RNGine::Registry &registry) {
  RNGine::SparseArray<RNGine::components::Text> &Texts =
      registry.getComponents<RNGine::components::Text>();

  for (size_t i = 0; i < Texts.size(); i++) {
    if (!Texts[i].has_value())
      continue;
    Texts[i]->text2 = std::to_string(registry._gameScore);
  }
};

RNGine::Registry::System CheckHealth = [](RNGine::Registry &registry) {
  RNGine::SparseArray<RNGine::components::Attackable> &Attackables =
      registry.getComponents<RNGine::components::Attackable>();

  for (size_t i = 0; i < Attackables.size(); i++) {
    if (!Attackables[i].has_value())
      continue;
    if (Attackables[i]->health <= 0) {
      registry._gameScore = registry._gameScore + Attackables[i]->points;
      registry.removeEntity(i);
    }
  }
};

namespace Rtype {
RNGine::Registry::SystemBundle engineSystems = {UpdateScore, CheckHealth};
}
