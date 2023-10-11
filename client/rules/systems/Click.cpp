/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** Click
*/

#include "rules/systems/Click.hpp"

RNGine::Registry::System CheckClickSystems = [](RNGine::Registry &registry) {
  RNGine::SparseArray<RNGine::components::Position> &Positions =
      registry.getComponents<RNGine::components::Position>();
  RNGine::SparseArray<RNGine::components::Clickable> &Clickables =
      registry.getComponents<RNGine::components::Clickable>();
  std::vector<std::pair<int, int>> *mouse = registry._mouseBinds;
  for (size_t i = 0; i < Clickables.size(); i++) {
    if (!Clickables[i].has_value() || !Positions[i].has_value())
      continue;
    for (auto &Click : *mouse) {
      if (Click.first >= Positions[i]->x &&
          Click.first <= Positions[i]->x + Clickables[i]->x &&
          Click.second >= Positions[i]->y &&
          Click.second <= Positions[i]->y + Clickables[i]->y) {
        std::cout << "CLICKED: " << Click.first << ", " << Click.second
                  << std::endl;
      }
    }
    mouse->clear();
  }
};

namespace Rtype {
RNGine::Registry::SystemBundle clickSystems = {CheckClickSystems};
}