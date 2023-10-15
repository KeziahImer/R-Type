
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
    std::mutex coreMutex;
    boost::asio::io_context ioContext;
    Rtype::Network network(ioContext, &core, coreMutex);
    std::cout << "MAIN memCore: " << &core << std::endl;
    Rtype::MenuScene menu(&core, network, ioContext, coreMutex);
    menu.load();
    core.manager.addScene(menu);
    std::thread networkThread([&]() { ioContext.run(); });
    core.loop();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
