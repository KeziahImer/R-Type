#include "rules/scenes/Menu.hpp"

#include "SFML/Graphics/Color.hpp"
#include "rngine/Keys.hpp"
#include "rngine/components/Attackable.hpp"
#include "rngine/components/Clickable.hpp"
#include "rngine/components/Collider.hpp"
#include "rngine/components/EnemyShoot.hpp"
#include "rngine/components/Movable.hpp"
#include "rngine/components/Shoot.hpp"
#include "rngine/components/healthBar.hpp"
#include "rngine/components/text.hpp"
#include "rules/systems/Click.hpp"
#include "rules/systems/Engine.hpp"
#include "rules/systems/Physics.hpp"
#include "rules/systems/Shoots.hpp"
#include <utility>

Rtype::MenuScene::MenuScene() {
  setId("menu");
  addBundle(Rtype::physicsSystems);
  addBundle(Rtype::shootsSystems);
  addBundle(Rtype::clickSystems);
  addBundle(Rtype::engineSystems);
  createPlayer(createEntity("player"));
  createBackground(createEntity("background"));
  for (int i = 0; i < 30; i++) {
    createEnemy(createEntity("enemy"), 1920 + (1000 * i), rand() % 1000 + 1);
  }
  createScore(createEntity("score"));
}

void Rtype::MenuScene::createBackground(RNGine::Entity e) {
  addComponent(e,
               RNGine::components::Sprite::createSprite(
                   "./assets/backgroundSpace.jpg", false, 514, 360, 0, 0, 0));
  addComponent(e, RNGine::components::Position::createPosition(0, 0));
  addComponent(e, RNGine::components::Size::createSize(3.73, 3));
}

void Rtype::MenuScene::createScore(RNGine::Entity e) {
  addComponent(e, RNGine::components::Position::createPosition(10, 10));
  addComponent(e, RNGine::components::Text::createText("SCORE: ", "0",
                                                       "./assets/FontGame.TTF",
                                                       sf::Color::White, 50));
}

void Rtype::MenuScene::createHealthBar(RNGine::Entity e, RNGine::Entity entity,
                                       float hp) {
  addComponent(e, RNGine::components::Position::createPosition(10, 10));
  addComponent(
      e, RNGine::components::healthBar::createhealthBar(
             hp, hp, entity, "./assets/FontGame.TTF", sf::Color::Green, 11));
}

void Rtype::MenuScene::createPlayer(RNGine::Entity e) {
  addComponent(e, RNGine::components::Sprite::createSprite(
                      "./assets/Player.gif", false, 33, 17, 2, 2, 1));
  addComponent(e, RNGine::components::Position::createPosition(25, 500));
  addComponent(e, RNGine::components::Size::createSize(3, 3));
  addComponent(e, RNGine::components::Velocity::createVelocity(0, 0));
  addComponent(e, RNGine::components::Collider::createCollider(33 * 3, 17 * 3));
  std::map<enum RNGine::Key, std::pair<float, float>> keybinds = {
      {RNGine::Down, std::make_pair(0, 0.75)},
      {RNGine::Left, std::make_pair(-0.75, 0)},
      {RNGine::Right, std::make_pair(0.75, 0)},
      {RNGine::Up, std::make_pair(0, -0.75)}};
  addComponent(e, RNGine::components::Movable::createmovable(keybinds));
  addComponent(e, RNGine::components::Shoot::createShoot(
                      RNGine::Space, 2, 0, 125,
                      std::chrono::duration_cast<std::chrono::milliseconds>(
                          std::chrono::system_clock::now().time_since_epoch())
                          .count(),
                      25, true));
  addComponent(e, RNGine::components::Selfdestroy::createSelfDestroy(
                      1920 + 150, 1080 + 150, -150, -150));
  addComponent(e,
               RNGine::components::Clickable::createClickable(33 * 3, 17 * 3));
  addComponent(
      e, RNGine::components::Attackable::createAttackable(500, 0, true, true));
  createHealthBar(createEntity("healthBar"), e, 500);
}

void Rtype::MenuScene::createEnemy(RNGine::Entity e, float posX, float posY) {
  addComponent(e, RNGine::components::Sprite::createSprite(
                      "./assets/Player.gif", true, 33, 17, 2, 3, 1));
  addComponent(e, RNGine::components::Position::createPosition(posX, posY));
  addComponent(e, RNGine::components::Size::createSize(3, 3));
  addComponent(e, RNGine::components::Velocity::createVelocity(-0.5, 0));
  addComponent(
      e, RNGine::components::Attackable::createAttackable(75, 25, false, true));
  addComponent(e, RNGine::components::Collider::createCollider(33 * 3, 17 * 3));
  addComponent(e, RNGine::components::Selfdestroy::createSelfDestroy(
                      posX + 150, 1080 + 150, -150, -150));
  addComponent(e, RNGine::components::EnemyShoot::createEnemyShoot(
                      -2, 0, 1000,
                      std::chrono::duration_cast<std::chrono::milliseconds>(
                          std::chrono::system_clock::now().time_since_epoch())
                          .count(),
                      25, false));
}