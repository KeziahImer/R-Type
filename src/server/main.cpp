#include "scenes/Game.hpp"
#include "scenes/Level1.hpp"
#include "scenes/Level2.hpp"
#include "scenes/Level3.hpp"
#include "scenes/Level4.hpp"
#include "scenes/Level5.hpp"
#include "scenes/Level6.hpp"
#include "scenes/Level7.hpp"
#include "scenes/Level8.hpp"
#include <chrono>
#include <iostream>
#include <thread>

#include "Rtype/Core.hpp"
#include "Server.hpp"

int main() {
  RNGine::Core core;
  Server::Core server(4242);
  Server::Scenes::Game game(core);
  core.AddScene("game", game);
  Server::Scenes::Level1 level1(core);
  core.AddScene("Level1", level1);
  Server::Scenes::Level2 level2(core);
  core.AddScene("Level2", level2);
  Server::Scenes::Level3 level3(core);
  core.AddScene("Level3", level3);
  Server::Scenes::Level4 level4(core);
  core.AddScene("Level4", level4);
  Server::Scenes::Level5 level5(core);
  core.AddScene("Level5", level5);
  Server::Scenes::Level6 level6(core);
  core.AddScene("Level6", level6);
  Server::Scenes::Level7 level7(core);
  core.AddScene("Level7", level7);
  Server::Scenes::Level8 level8(core);
  core.AddScene("Level8", level8);

  while (true) {
    if (!core.Update())
      continue;
    server.Update(core);
  }
  return 0;
}