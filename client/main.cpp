
#include <iostream>

#include "SFML/Window/Keyboard.hpp"
#include "rngine/Core.hpp"
#include "rngine/Keys.hpp"
#include "rules/scenes/Menu.hpp"
#include "Network.hpp"

int main() {
  boost::asio::io_context ioContext;
  Rtype::Network network(ioContext);

  RNGine::Core core(network);
  Rtype::MenuScene menu;
  
  network.sendRequest();

  menu.load();
  core.manager.addScene(menu);
  ioContext.run();
  core.loop();
  return 0;
}
