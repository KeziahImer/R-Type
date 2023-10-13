#include "rules/scenes/Menu.hpp"
#include "rules/scenes/Lobby.hpp"

Rtype::MenuScene::MenuScene(RNGine::Core &core) : _core(core) {
  setId("menu");
  addBundle(Rtype::clickSystems);
  createBackground(createEntity("background"));
  createButton(
      createEntity("button"), "SOLO",
      [&] {
        Rtype::GameScene game;
        core.manager.load(core.manager.addScene(game));
      },
      810, 400, 300, 50);
  createButton(
      createEntity("buttonMulti"), "MULTIPLAYER",
      [&] {
        std::cout << "create lobby" << std::endl;
        boost::asio::io_context ioContext;
        Rtype::Network network(ioContext, core);
        Rtype::LobbyScene lobby(core, &network, &ioContext);
        _ioContext = &ioContext;
        _network = &network;
        std::cout << "created lobby" << std::endl;
        core.manager.load(core.manager.addScene(lobby));
        std::cout << "loaded lobby" << std::endl;
      },
      810, 475, 300, 50);
  createButton(
      createEntity("buttonExit"), "EXIT", [&] { core.setRunning(false); }, 810,
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
