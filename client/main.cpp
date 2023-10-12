
#include <iostream>

#include "SFML/Window/Keyboard.hpp"
#include "rngine/Core.hpp"
#include "rngine/Keys.hpp"
#include "rules/scenes/Menu.hpp"

int main() {
  RNGine::Core core;
  Rtype::MenuScene menu;
  menu.load();
  core.manager.addScene(menu);
  core.loop();

  return 0;
}
