#include "rules/scenes/Lobby.hpp"

Rtype::LobbyScene::LobbyScene(RNGine::Core &core) {
  setId("menu");
  addBundle(Rtype::clickSystems);
  createBackground(createEntity("background"));
  createButton(
      createEntity("button"), "START GAME",
      [&] {
        Rtype::GameScene game;
        core.manager.addScene(game);
        core.manager.load(core.manager.addScene(game));
      },
      810, 400, 300, 50);
  createTexte(createEntity("players"), "Players: ", 25);
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