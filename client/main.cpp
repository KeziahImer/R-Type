
#include <iostream>

#include "SFML/Window/Keyboard.hpp"
#include "rngine/Core.hpp"
#include "rngine/Keys.hpp"
#include "rules/scenes/Menu.hpp"
#include "Network.hpp"

int main() {
  std::cout << "Il entre" << std::endl;
  boost::asio::io_context ioContext;
  Rtype::Network network(ioContext);
  std::cout << "Il reste bloqué le chien" << std::endl;

  std::cout << "Allo print moi stp" << std::endl;
  // ioContext.run();

  // RNGine::Core core(network);
  RNGine::Core core;
  Rtype::MenuScene menu;
  
  // network.sendRequest();

  menu.load();
  core.manager.addScene(menu);
  core.loop();
  return 0;
}
