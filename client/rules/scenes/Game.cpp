#include "rules/scenes/Game.hpp"

Rtype::GameScene::GameScene() {
  setId("game");
  addBundle(Rtype::physicsSystems);
  addBundle(Rtype::shootsSystems);
  addBundle(Rtype::clickSystems);
  addBundle(Rtype::engineSystems);
  createPlayer(createEntity("player"));
  createBackground(createEntity("background"), 0, 0);
  createBackground(createEntity("background"), 1920, 0);
  createScore(createEntity("score"));
  createWave(30, 1920);
  createWave(30, 20000);
  createWave(30, 40000);
}

void Rtype::GameScene::createBackground(RNGine::Entity e, float x, float y) {
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

void Rtype::GameScene::createWave(int waveSize, int waveStart) {
  for (int i = 0; i < waveSize; i++) {
    createEnemy(createEntity("enemy"), waveStart + ((rand() % 1000 + 1) * i),
                rand() % 1000 + 1);
  }
}

void Rtype::GameScene::createScore(RNGine::Entity e) {
  addComponent(e, RNGine::components::Position::createPosition(10, 10));
  addComponent(e, RNGine::components::Text::createText(
                      "SCORE: ", "0", "./assets/FontGame.TTF",
                      sf::Color(90, 168, 246), 25));
}

void Rtype::GameScene::createHealthBar(RNGine::Entity e, RNGine::Entity entity,
                                       float hp) {
  addComponent(e, RNGine::components::Position::createPosition(10, 10));
  addComponent(
      e, RNGine::components::healthBar::createhealthBar(
             hp, hp, entity, "./assets/FontGame.TTF", sf::Color::Green, 11));
}

void Rtype::GameScene::createPlayer(RNGine::Entity e) {
  addComponent(e, RNGine::components::Sprite::createSprite(
                      "./assets/Player.gif", false, 33, 17, 2, 2, 2));
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
  addComponent(
      e, RNGine::components::Attackable::createAttackable(500, 0, true, true));
  createHealthBar(createEntity("healthBar"), e, 500);
}

void Rtype::GameScene::createEnemy(RNGine::Entity e, float posX, float posY) {
  addComponent(e, RNGine::components::Sprite::createSprite(
                      "./assets/Player.gif", true, 33, 17, 2, 3, 2));
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