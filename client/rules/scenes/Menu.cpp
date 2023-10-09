#include "rules/scenes/Menu.hpp"

#include "rngine/Keys.hpp"
#include "rngine/components/Movable.hpp"
#include "rules/systems/Physics.hpp"
#include <utility>

Rtype::MenuScene::MenuScene() {
  setId("menu");
  addBundle(Rtype::physicsSystems);
  createPlayer(createEntity("player"));
  createBackground(createEntity("background"));
}

void Rtype::MenuScene::createBackground(RNGine::Entity e) {
  addComponent(e,
               RNGine::components::Sprite::createSprite(
                   "./assets/backgroundSpace.jpg", false, 514, 360, 0, 0, 0));
  addComponent(e, RNGine::components::Position::createPosition(0, 0));
  addComponent(e, RNGine::components::Size::createSize(3.73, 3));
}

void Rtype::MenuScene::createPlayer(RNGine::Entity e) {
  addComponent(e, RNGine::components::Sprite::createSprite(
                      "./assets/Player.gif", false, 33, 17, 2, 2, 1));
  addComponent(e, RNGine::components::Position::createPosition(25, 500));
  addComponent(e, RNGine::components::Size::createSize(3, 3));
  addComponent(e, RNGine::components::Velocity::createVelocity(0, 0));
  std::map<enum RNGine::Key, std::pair<float, float>> keybinds = {
      {RNGine::S, std::make_pair(0, 0.5)},
      {RNGine::Q, std::make_pair(-0.5, 0)},
      {RNGine::D, std::make_pair(0.5, 0)},
      {RNGine::Z, std::make_pair(0, -0.5)}};
  addComponent(e, RNGine::components::Movable::createmovable(keybinds));
}