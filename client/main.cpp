
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
    boost::asio::io_context ioContext;
    std::mutex mutex;
    Rtype::Network network(ioContext, &core, mutex);
    Rtype::MenuScene menu(&core, network, ioContext);
    menu.load();
    core.manager.addScene(menu);
    std::thread networkThread([&ioContext]() { ioContext.run(); });
    core.loop(mutex);
    ioContext.stop();
    networkThread.join();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
