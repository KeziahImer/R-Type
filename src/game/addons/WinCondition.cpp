#include "Rtype/addons/winCondition.hpp"
#include "Rtype/addons/WinConditionComponent.hpp"
#include <iostream>

void Client::Components::WinConditionSystem(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &winConditions = scene.GetComponents<Client::Components::WinCondition>();
  auto &winConditionEntities =
      scene.GetComponents<Rtype::Components::WinCondition>();
  auto &transforms = scene.GetComponents<RNGine::Components::Transform>();

  for (int i = 0; i < winConditionEntities.size(); i++) {
    if (!winConditionEntities[i].has_value())
      continue;
    for (int x = 0; x < winConditions.size(); x++) {
      if (!winConditions[x].has_value())
        continue;
      if (std::find(winConditions[x]->entities.begin(),
                    winConditions[x]->entities.end(),
                    i) == winConditions[x]->entities.end()) {
        winConditions[x]->entities.push_back(i);
        winConditions[x]->boss = false;
      }
    }
  }
  auto max = winConditions.size();
  for (size_t i = 0; i < max; i++) {
    auto &winCondition = winConditions[i];
    if (!winCondition.has_value())
      continue;
    winCondition->lastUpdate = winCondition->lastUpdate + core.deltaTime;
    if (winCondition->lastUpdate < winCondition->endGame)
      continue;
    for (int x = 0; x < winCondition->entities.size(); x++) {
      if (!transforms[winCondition->entities[x]].has_value()) {
        winCondition->entities.erase(winCondition->entities.begin() + x);
      }
    }
    if (winCondition->boss)
      continue;
    if (winCondition->entities.size() == 0) {
      core.SetActualScene("victory");
    }
  }
}
