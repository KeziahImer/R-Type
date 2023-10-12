
#include <iostream>

#include "SFML/Window/Keyboard.hpp"
#include "rngine/Core.hpp"
#include "rngine/Keys.hpp"
#include "rules/scenes/Menu.hpp"
#include "Network.hpp"

int main() {
  RNGine::Core core;
  Rtype::MenuScene menu;
  menu.load();
  core.manager.addScene(menu);
  boost::asio::io_context ioContext;
  Rtype::Network network(ioContext, core.manager.getActualScene().getRegistry());
  ioContext.run();
  core.loop();
  return 0;
}
