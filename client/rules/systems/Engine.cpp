#include "rules/systems/Engine.hpp"
#include "client/Network.hpp"
#include "rngine/components/Networked.hpp"
#include "rngine/components/PlayerId.hpp"
#include "rngine/components/Position.hpp"
#include "rngine/components/Size.hpp"
#include "rngine/components/Sprite.hpp"
#include "rngine/components/healthBar.hpp"
#include <string>

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
  RNGine::SparseArray<RNGine::components::healthBar> &healthBars =
      registry.getComponents<RNGine::components::healthBar>();
  for (size_t i = 0; i < Attackables.size(); i++) {
    if (!Attackables[i].has_value())
      continue;
    if (Attackables[i]->health <= 0) {
      registry._gameScore = registry._gameScore + Attackables[i]->points;
      for (size_t x = 0; x < healthBars.size(); x++) {
        if (!healthBars[x].has_value())
          continue;
        if (healthBars[x]->entity == i) {
          std::cout << "REMOVE HEALTHBAR: " << x << std::endl;
          registry.removeEntity(x);
        }
      }
      registry.removeEntity(i);
    }
  }
};

RNGine::Registry::System UpdateHealthBar = [](RNGine::Registry &registry) {
  RNGine::SparseArray<RNGine::components::healthBar> &healthBars =
      registry.getComponents<RNGine::components::healthBar>();
  RNGine::SparseArray<RNGine::components::Position> &Positions =
      registry.getComponents<RNGine::components::Position>();
  RNGine::SparseArray<RNGine::components::Sprite> &Sprites =
      registry.getComponents<RNGine::components::Sprite>();
  RNGine::SparseArray<RNGine::components::Size> &Sizes =
      registry.getComponents<RNGine::components::Size>();
  RNGine::SparseArray<RNGine::components::Attackable> &Attackables =
      registry.getComponents<RNGine::components::Attackable>();

  for (size_t i = 0; i < healthBars.size(); i++) {
    if (!healthBars[i].has_value() ||
        !Attackables[healthBars[i]->entity].has_value())
      continue;
    healthBars[i]->hp = Attackables[healthBars[i]->entity]->health;
    healthBars[i]->textHealth = std::to_string((int)healthBars[i]->hp) + "/" +
                                std::to_string((int)healthBars[i]->maxHp);
    if (!Positions[healthBars[i]->entity].has_value() ||
        !Positions[i].has_value() ||
        !Sprites[healthBars[i]->entity].has_value() ||
        !Sizes[healthBars[i]->entity].has_value())
      continue;
    Positions[i]->x = Positions[healthBars[i]->entity]->x;
    Positions[i]->y = Positions[healthBars[i]->entity]->y +
                      Sprites[healthBars[i]->entity]->sizeTileY *
                          Sizes[healthBars[i]->entity]->scaleY;
  }
};

namespace Rtype {
RNGine::Registry::SystemBundle engineSystems = {UpdateScore, CheckHealth,
                                                UpdateHealthBar};
}