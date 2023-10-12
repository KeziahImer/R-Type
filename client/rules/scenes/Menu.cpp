#include "rules/scenes/Menu.hpp"
#include "rules/scenes/Lobby.hpp"

Rtype::MenuScene::MenuScene(RNGine::Core &core) {
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
        Rtype::LobbyScene lobby(core);
        core.manager.load(core.manager.addScene(lobby));
      },
      810, 500, 300, 50);
  createButton(
      createEntity("buttonExit"), "EXIT", [&] { core.setRunning(false); }, 810,
      600, 300, 50);
}

void Rtype::MenuScene::createBackground(RNGine::Entity e) {
  addComponent(e,
               RNGine::components::Sprite::createSprite(
                   "./assets/backgroundSpace.jpg", false, 514, 360, 0, 0, 0));
  addComponent(e, RNGine::components::Position::createPosition(0, 0));
  addComponent(e, RNGine::components::Size::createSize(3.73, 3));
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
