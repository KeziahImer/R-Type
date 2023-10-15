#include "rules/scenes/MultiplayerGame.hpp"
#include "rngine/components/PlayerId.hpp"

Rtype::GameMultiScene::GameMultiScene(int id, int playerNumber,
                                      Rtype::Network &network,
                                      boost::asio::io_context &ioContext)
    : _ID(id), _playersNbr(playerNumber), _network(network),
      _ioContext(ioContext) {
  setId("gameMulti");
  addBundle(Rtype::physicsSystems);
  addBundle(Rtype::shootsSystems);
  addBundle(Rtype::clickSystems);
  addBundle(Rtype::engineSystems);
  for (int i = 0; i < 4; i++) {
    if (i + 1 == id) {
      createPlayer(createEntity("player"), i + 1);
    } else {
      createAlly(createEntity("Ally"), i + 1);
    }
  }
  createBackground(createEntity("background"), 0, 0);
  createBackground(createEntity("background"), 1920, 0);
  for (int i = 0; i < 30; i++) {
    createEnemy(createEntity("enemy"), 1920 + (1000 * i), rand() % 1000 + 1);
  }
  createScore(createEntity("score"));
}

void Rtype::GameMultiScene::createBackground(RNGine::Entity e, float x,
                                             float y) {
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

void Rtype::GameMultiScene::createScore(RNGine::Entity e) {
  addComponent(e, RNGine::components::Position::createPosition(10, 10));
  addComponent(e, RNGine::components::Text::createText(
                      "SCORE: ", "0", "./assets/FontGame.TTF",
                      sf::Color(90, 168, 246), 25));
}

void Rtype::GameMultiScene::createHealthBar(RNGine::Entity e,
                                            RNGine::Entity entity, float hp) {
  addComponent(e, RNGine::components::Position::createPosition(10, 10));
  addComponent(
      e, RNGine::components::healthBar::createhealthBar(
             hp, hp, entity, "./assets/FontGame.TTF", sf::Color::Green, 11));
}

void Rtype::GameMultiScene::createPlayer(RNGine::Entity e, int id) {
  int spriteY = id - 1;
  if (spriteY > 2)
    spriteY++;
  addComponent(e, RNGine::components::Sprite::createSprite(
                      "./assets/Player.gif", false, 33, 17, 2, spriteY, 2));
  addComponent(e, RNGine::components::Position::createPosition(25, 200 * id));
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
  addComponent(e, RNGine::components::PlayerId::createPlayerId(id));
}

void Rtype::GameMultiScene::createAlly(RNGine::Entity e, int id) {
  int spriteY = id - 1;
  if (spriteY > 2)
    spriteY++;
  addComponent(e, RNGine::components::Sprite::createSprite(
                      "./assets/Player.gif", false, 33, 17, 2, spriteY, 2));
  addComponent(e, RNGine::components::Position::createPosition(25, 200 * id));
  addComponent(e, RNGine::components::Size::createSize(3, 3));
  addComponent(e, RNGine::components::Velocity::createVelocity(0, 0));
  addComponent(e, RNGine::components::Collider::createCollider(33 * 3, 17 * 3));
  addComponent(
      e, RNGine::components::Attackable::createAttackable(500, 0, true, true));
  createHealthBar(createEntity("healthBar"), e, 500);
  addComponent(e, RNGine::components::PlayerId::createPlayerId(id));
}

void Rtype::GameMultiScene::createEnemy(RNGine::Entity e, float posX,
                                        float posY) {
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