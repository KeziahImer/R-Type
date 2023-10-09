
#include <iostream>

#include "rngine/Core.hpp"
#include "rules/scenes/Menu.hpp"

int main() {
  RNGine::Core core;
  Rtype::MenuScene menu;
  menu.load();
  core.manager.addScene(menu);
  core.loop();

  return 0;
}
