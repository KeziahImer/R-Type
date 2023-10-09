#include "rules/scenes/Menu.hpp"

#include "rules/systems/Physics.hpp"

Rtype::MenuScene::MenuScene() {
  setId("menu");
  addBundle(Rtype::physicsSystems);
  createBackground(createEntity("background"));
  createPlayer(createEntity("player"));
}

void Rtype::MenuScene::createBackground(RNGine::Entity e) {
  addComponent(e, RNGine::components::Sprite::createSprite(
                      "./assets/backgroundSpace.jpg", false, 514, 360, 0, 0));
  addComponent(e, RNGine::components::Position::createPosition(0, 0));
  addComponent(e, RNGine::components::Size::createSize(3.73, 3));
  addComponent(e, RNGine::components::Velocity::createVelocity(-0.2, 0));
}

void Rtype::MenuScene::createPlayer(RNGine::Entity e) {
  addComponent(e, RNGine::components::Sprite::createSprite(
                      "./assets/backgroundSpace.jpg", false, 514, 360, 0, 0));
  addComponent(e, RNGine::components::Position::createPosition(0, 0));
  addComponent(e, RNGine::components::Size::createSize(3.73, 3));
  addComponent(e, RNGine::components::Velocity::createVelocity(-0.2, 0));
}