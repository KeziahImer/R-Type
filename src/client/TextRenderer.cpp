#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "RNGine/Core.hpp"
#include "RNGine/components/Transform.hpp"
#include "Rtype/addons/IsLoot.hpp"
#include "Rtype/addons/NetworkId.hpp"
#include "TextRenderer.hpp"
#include "components/MousePosition.hpp"
#include "components/NumberLevels.hpp"
namespace r {
#include "raylib.h"
}

void Client::TextRenderer::UpdateTexts(RNGine::Scene &scene) {
  auto &scores = scene.GetComponents<RNGine::Components::Score>();
  auto &healthes = scene.GetComponents<RNGine::Components::Attackable>();
  auto &transforms = scene.GetComponents<RNGine::Components::Transform>();
  auto &numberLevel =
      scene.GetComponents<Client::Components::NumberLevel>()[scene.GetEntity(
          "numberLevels")];
  auto &networkId =
      scene.GetComponents<Rtype::Components::networkId>()[scene.GetEntity(
          "networkId")];

  auto max = scores.size();
  for (size_t i = 0; i < max; i++) {
    auto &score = scores[i];
    if (!score.has_value())
      continue;
    std::string toPrint;
    std::string toPrintPowerUp;
    if (networkId.has_value()) {
      auto &scoresNet =
          scene.GetComponents<RNGine::Components::Score>()[scene.GetEntity(
              "ship-" + std::to_string(networkId->id))];
      toPrint = "SCORE: " + std::to_string(scoresNet->score);
      toPrintPowerUp = std::to_string(scoresNet->numberPowerUp);
    } else {
      toPrint = "SCORE: " + std::to_string(score->score);
      toPrintPowerUp = std::to_string(score->numberPowerUp);
    }
    r::DrawText(toPrint.c_str(), 0, 50, 40, r::LIGHTGRAY);
    r::DrawText(toPrintPowerUp.c_str(), 165, 995, 40, r::LIGHTGRAY);
  }
  for (size_t i = 0; i < max; i++) {
    auto &health = healthes[i];
    if (!health.has_value())
      continue;
    std::string toPrint;
    if (networkId.has_value()) {
      auto &healthNet =
          scene.GetComponents<RNGine::Components::Attackable>()[scene.GetEntity(
              "ship-" + std::to_string(networkId->id))];
      toPrint = "HEALTH: " + std::to_string(healthNet->health);
    } else {
      toPrint = "HEALTH: " + std::to_string(health->health);
    }
    r::DrawText(toPrint.c_str(), 0, 0, 40, r::RED);
  }
  if (!numberLevel.has_value())
    return;
  for (int i = 0; i < numberLevel->numberLevel; i++) {
    auto entity = scene.GetEntity("button-" + std::to_string(i + 1));
    std::string toPrint = std::to_string(i + 1);
    if (transforms[entity].has_value()) {
      r::DrawText(toPrint.c_str(), transforms[entity]->x - 25,
                  transforms[entity]->y - 50, 100, r::WHITE);
    }
  }
}
