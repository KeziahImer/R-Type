#include "rules/scenes/Menu.hpp"

#include "rngine/Keys.hpp"
#include "rngine/components/Attackable.hpp"
#include "rngine/components/Collider.hpp"
#include "rngine/components/Movable.hpp"
#include "rngine/components/Shoot.hpp"
#include "rngine/components/Clickable.hpp"
#include "rules/systems/Physics.hpp"
#include "rules/systems/Shoots.hpp"
#include "rules/systems/Click.hpp"
#include <utility>

Rtype::MenuScene::MenuScene() {
  setId("menu");
  addBundle(Rtype::physicsSystems);
  addBundle(Rtype::shootsSystems);
  addBundle(Rtype::clickSystems);
  createPlayer(createEntity("player"));
  createBackground(createEntity("background"));
  createEnemy(createEntity("enemy"), 150);
  createEnemy(createEntity("enemy"), 500);
  createEnemy(createEntity("enemy"), 750);
  createEnemy(createEntity("enemy"), 900);
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
  addComponent(e, RNGine::components::Shoot::createShoot(
                      RNGine::Space, 2, 0, 250,
                      std::chrono::duration_cast<std::chrono::milliseconds>(
                          std::chrono::system_clock::now().time_since_epoch())
                          .count(),
                      25));
  addComponent(e, RNGine::components::Selfdestroy::createSelfDestroy(
                      1920 + 150, 1080 + 150, -150, -150));
  addComponent(e, RNGine::components::Clickable::createClickable(33 * 3, 17 * 3));
}

void Rtype::MenuScene::createEnemy(RNGine::Entity e, float posY) {
  addComponent(e, RNGine::components::Sprite::createSprite(
                      "./assets/Player.gif", true, 33, 17, 2, 3, 1));
  addComponent(e, RNGine::components::Position::createPosition(1925, posY));
  addComponent(e, RNGine::components::Size::createSize(3, 3));
  addComponent(e, RNGine::components::Velocity::createVelocity(-0.5, 0));
  addComponent(e, RNGine::components::Attackable::createAttackable(10));
  addComponent(e, RNGine::components::Collider::createCollider(33 * 3, 17 * 3));
  addComponent(e, RNGine::components::Selfdestroy::createSelfDestroy(
                      1920 + 150, 1080 + 150, -150, -150));
}