#include <chrono>
#include <iostream>
#include <thread>

#include "Rtype/Core.hpp"
#include "Server.hpp"

int main() {
  RNGine::Core core;
  Rtype::Core game;
  Server::Core server(4242);
  core.AddScene("game", game);

  while (true) {
    if (!core.Update())
      continue;
    server.Update(core);
  }
  return 0;
}