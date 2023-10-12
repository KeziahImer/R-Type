
#include <iostream>

#include "SFML/Window/Keyboard.hpp"
#include "rngine/Core.hpp"
#include "rngine/Keys.hpp"
#include "rules/scenes/Game.hpp"
#include "rules/scenes/Menu.hpp"

int main() {
  RNGine::Core core;
  Rtype::MenuScene menu(core);
  Rtype::GameScene game;
  menu.load();
  core.manager.addScene(menu);
  core.manager.addScene(game);
  core.loop();

  return 0;
}
