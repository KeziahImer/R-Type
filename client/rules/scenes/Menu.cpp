#include "rules/scenes/Menu.hpp"

#include "SFML/Graphics/Color.hpp"
#include "rngine/Keys.hpp"
#include "rngine/components/Attackable.hpp"
#include "rngine/components/Collider.hpp"
#include "rngine/components/EnemyShoot.hpp"
#include "rngine/components/Movable.hpp"
#include "rngine/components/Shoot.hpp"
#include "rngine/components/Velocity.hpp"
#include "rngine/components/text.hpp"
#include "rules/scenes/Lobby.hpp"
#include "rules/systems/Engine.hpp"
#include "rules/systems/Physics.hpp"

Rtype::MenuScene::MenuScene(RNGine::Core *core, Rtype::Network &network,
                            boost::asio::io_context &ioContext)
    : _network(network), _ioContext(ioContext) {
  setId("menu");
  _core = core;
  addBundle(Rtype::clickSystems);
  addBundle(Rtype::physicsSystems);
  createBackground(createEntity("background"), 0, 0);
  createBackground(createEntity("background1"), 1920, 0);
  createButton(
      createEntity("button"), "SOLO",
      [core] {
        Rtype::GameScene game;
        core->manager.load(core->manager.addScene(game));
      },
      810, 400, 300, 50);
  createButton(
      createEntity("buttonMulti"), "MULTIPLAYER",
      [core, &network, &ioContext, this] {
        Rtype::LobbyScene lobby(core, network, ioContext);
        core->manager.load(core->manager.addScene(lobby));
        lobby.initNetwork();
      },
      810, 475, 300, 50);
  createButton(
      createEntity("buttonExit"), "EXIT", [core] { core->setRunning(false); },
      810, 550, 300, 50);
  createLogo(createEntity("logo"));
}

void Rtype::MenuScene::createBackground(RNGine::Entity e, float x, float y) {
  addComponent(e,
               RNGine::components::Sprite::createSprite(
                   "./assets/backgroundSpace.png", false, 512, 512, 0, 0, 0));
  addComponent(e, RNGine::components::Position::createPosition(x, y));
  addComponent(e, RNGine::components::Size::createSize((float)1920 / 512,
                                                       (float)1080 / 512));
  addComponent(
      e, RNGine::components::InfiniteScroll::createInfiniteScroll(-1920, 1920));
  addComponent(e, RNGine::components::Velocity::createVelocity(-0.05, 0));
  RNGine::Entity background2 = createEntity("background2");
  addComponent(background2,
               RNGine::components::Sprite::createSprite(
                   "./assets/Parallax60.png", false, 500, 500, 0, 0, 1));
  addComponent(background2, RNGine::components::Position::createPosition(x, y));
  addComponent(background2, RNGine::components::Size::createSize(
                                (float)1920 / 500, (float)1080 / 500));
  addComponent(
      background2,
      RNGine::components::InfiniteScroll::createInfiniteScroll(-1920, 1920));
  addComponent(background2,
               RNGine::components::Velocity::createVelocity(-0.1, 0));
}

void Rtype::MenuScene::createLogo(RNGine::Entity e) {
  addComponent(e, RNGine::components::Sprite::createSprite(
                      "./assets/RTypeLogo.png", false, 500, 146, 0, 0, 2));
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
