#include "rules/scenes/Menu.hpp"
#include "rules/scenes/Lobby.hpp"

Rtype::MenuScene::MenuScene(RNGine::Core &core, Rtype::Network &network,
                            boost::asio::io_context &ioContext)
    : _core(core), _network(network), _ioContext(ioContext) {
  setId("menu");
  addBundle(Rtype::clickSystems);
  createBackground(createEntity("background"));
  createButton(
      createEntity("button"), "SOLO",
      [&] {
        Rtype::GameScene game;
        _core.manager.load(_core.manager.addScene(game));
      },
      810, 400, 300, 50);
  createButton(
      createEntity("buttonMulti"), "MULTIPLAYER",
      [&] {
        Rtype::LobbyScene lobby(_core, _network, _ioContext);
        _core.manager.load(_core.manager.addScene(lobby));
        lobby.initNetwork();
      },
      810, 475, 300, 50);
  createButton(
      createEntity("buttonExit"), "EXIT", [&] { _core.setRunning(false); }, 810,
      550, 300, 50);
  createLogo(createEntity("logo"));
}

void Rtype::MenuScene::createBackground(RNGine::Entity e) {
  addComponent(e,
               RNGine::components::Sprite::createSprite(
                   "./assets/backgroundSpace.jpg", false, 514, 360, 0, 0, 0));
  addComponent(e, RNGine::components::Position::createPosition(0, 0));
  addComponent(e, RNGine::components::Size::createSize(3.73, 3));
}

void Rtype::MenuScene::createLogo(RNGine::Entity e) {
  addComponent(e, RNGine::components::Sprite::createSprite(
                      "./assets/RTypeLogo.png", false, 500, 146, 0, 0, 1));
  addComponent(e, RNGine::components::Position::createPosition(710, 250));
  addComponent(e, RNGine::components::Size::createSize(1, 1));
}

void Rtype::MenuScene::createButton(RNGine::Entity e, std::string text,
                                    std::function<void(void)> function,
                                    float posX, float posY, float sizeX,
                                    float sizeY) {
  addComponent(e, RNGine::components::Position::createPosition(posX, posY));
  addComponent(e, RNGine::components::Button::createClickable(
                      sizeX, sizeY, function, text, sf::Color(90, 168, 246),
                      "./assets/FontGame.TTF", sizeY / 2));
}
