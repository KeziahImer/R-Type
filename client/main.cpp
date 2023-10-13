
#include <iostream>
#include <thread>

#include "Network.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "rngine/Core.hpp"
#include "rngine/Keys.hpp"
#include "rules/scenes/Menu.hpp"

int main() {
  try {
    boost::asio::io_context ioContext;
    RNGine::Core core;
    Rtype::Network network(ioContext, core);
    Rtype::MenuScene menu;
    menu.load();
    core.manager.addScene(menu);
    network.sendRequest(LOGIN, NONE, "");
    std::thread networkThread([&]() {
      while (1)
        ioContext.run();
    });
    core.loop();
    ioContext.stop();
    networkThread.join();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
