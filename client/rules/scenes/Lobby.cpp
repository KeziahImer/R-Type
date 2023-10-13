#include "rules/scenes/Lobby.hpp"
#include "rngine/Registry.hpp"
#include "rngine/components/text.hpp"
#include "rules/scenes/MultiplayerGame.hpp"
#include <string>
#include <thread>

Rtype::LobbyScene::LobbyScene(RNGine::Core &core, Rtype::Network *network,
                              boost::asio::io_context *ioContext)
    : _core(core), _network(network), _ioContext(ioContext) {
  setId("lobby");
  std::cout << "before request" << std::endl;
  _network->sendRequest(LOGIN, NONE, "");
  std::cout << "after request" << std::endl;
  addBundle(Rtype::clickSystems);
  createBackground(createEntity("background"));
  createButton(
      createEntity("button"), "START GAME",
      [&] {
        Rtype::GameMultiScene gameMulti(_ID, _playersNbr, _network, _ioContext,
                                        _networkThread);
        core.manager.load(core.manager.addScene(gameMulti));
      },
      810, 400, 300, 50);
  createTexte(createEntity("players"), "Players: ", 25);
  std::cout << "before thread" << std::endl;
  _networkThread = new std::thread([&]() {
    std::cout << "run" << std::endl;
    while (true) {
      _ioContext->run();
    }
    std::cout << "after run" << std::endl;
  });
  std::cout << "after thread" << std::endl;
}

void Rtype::LobbyScene::createBackground(RNGine::Entity e) {
  addComponent(e,
               RNGine::components::Sprite::createSprite(
                   "./assets/backgroundSpace.jpg", false, 514, 360, 0, 0, 0));
  addComponent(e, RNGine::components::Position::createPosition(0, 0));
  addComponent(e, RNGine::components::Size::createSize(3.73, 3));
}

void Rtype::LobbyScene::createButton(RNGine::Entity e, std::string text,
                                     std::function<void(void)> function,
                                     float posX, float posY, float sizeX,
                                     float sizeY) {
  addComponent(e, RNGine::components::Position::createPosition(posX, posY));
  addComponent(e, RNGine::components::Button::createClickable(
                      sizeX, sizeY, function, text, sf::Color(90, 168, 246),
                      "./assets/FontGame.TTF", sizeY / 2));
}

void Rtype::LobbyScene::createTexte(RNGine::Entity e, std::string text,
                                    int CharacterSize) {
  addComponent(e, RNGine::components::Position::createPosition(10, 10));
  addComponent(e, RNGine::components::Text::createText(
                      text, "1", "./assets/FontGame.TTF",
                      sf::Color(90, 168, 246), CharacterSize));
}

void Rtype::LobbyScene::setNumberPlayers(int nbrPLayers) {
  _playersNbr = nbrPLayers;
  auto &Texts = _core.manager.getActualScene()
                    .getRegistry()
                    .getComponents<RNGine::components::Text>();
  for (int i = 0; i < Texts.size(); i++) {
    if (!Texts[i].has_value())
      continue;
    Texts[i]->text2 = std::to_string(nbrPLayers);
  }
}

void Rtype::LobbyScene::setIDPlayer(int id) { _ID = id; }