
#include <iostream>
#include <thread>

#include "Network.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "rngine/Core.hpp"
#include "rngine/Keys.hpp"
#include "rules/scenes/Menu.hpp"

int main() {
  try {
    RNGine::Core core;
    Rtype::MenuScene menu(core);
    menu.load();
    core.manager.addScene(menu);
    core.loop();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
