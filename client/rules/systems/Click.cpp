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
  RNGine::SparseArray<RNGine::components::Button> &Clickables =
      registry.getComponents<RNGine::components::Button>();
  std::vector<std::pair<int, int>> *mouse = registry._mouseBinds;
  for (size_t i = 0; i < Clickables.size(); i++) {
    std::cout << "START for clickables: " << i << std::endl;
    if (!Clickables[i].has_value() || !Positions[i].has_value())
      continue;
    for (auto &Click : *mouse) {
      std::cout << "check mouse click" << std::endl;
      if (Click.first >= Positions[i]->x &&
          Click.first <= Positions[i]->x + Clickables[i]->x &&
          Click.second >= Positions[i]->y &&
          Click.second <= Positions[i]->y + Clickables[i]->y) {
        std::cout << "just clicked" << std::endl;
        Clickables[i]->function();
        std::cout << "after function clicked" << std::endl;
      }
      std::cout << "before check mouse click: " << Click.first << std::endl;
    }
    std::cout << "exit for click" << std::endl;
  }
  std::cout << "exit for clickables" << std::endl;
  mouse->clear();
  std::cout << "end system" << std::endl;
};

namespace Rtype {
RNGine::Registry::SystemBundle clickSystems = {CheckClickSystems};
}