#include "rules/scenes/MultiplayerGame.hpp"
#include "rngine/Keys.hpp"
#include "rngine/components/Attackable.hpp"
#include "rngine/components/Networked.hpp"
#include "rngine/components/PlayerId.hpp"
#include "rngine/components/Position.hpp"
#include "rngine/components/Shoot.hpp"
#include "rngine/components/Size.hpp"
#include "rngine/components/Sprite.hpp"
#include "rngine/components/Velocity.hpp"

Rtype::GameMultiScene::GameMultiScene(int id, int playerNumber,
                                      Rtype::Network *network,
                                      boost::asio::io_context &ioContext)
    : _ID(id), _playersNbr(playerNumber), _network(network),
      _ioContext(ioContext) {
  setId("gameMulti");
  addBundle(Rtype::physicsSystems);
  addBundle(Rtype::shootsSystems);
  addBundle(Rtype::clickSystems);
  addBundle(Rtype::engineSystems);
  for (int i = 0; i < playerNumber; i++) {
    if (i + 1 == id) {
      createPlayer(createEntity("player"), i + 1, network);
    } else {
      createAlly(createEntity("Ally"), i + 1);
    }
  }
  createBackground(createEntity("background"), 0, 0);
  createBackground(createEntity("background"), 1920, 0);
  createScore(createEntity("score"));
  createWave(30, 1920);
  createWave(30, 20000);
  createWave(30, 40000);
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

void Rtype::GameMultiScene::createPlayer(RNGine::Entity e, int id,
                                         Rtype::Network *network) {
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
  addComponent(e, RNGine::components::Networked::createNetworked(network));
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
  addComponent(e, RNGine::components::Shoot::createShoot(
                      RNGine::Delete, 2, 0, 125,
                      std::chrono::duration_cast<std::chrono::milliseconds>(
                          std::chrono::system_clock::now().time_since_epoch())
                          .count(),
                      25, true));
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
void Rtype::GameMultiScene::createWave(int waveSize, int waveStart) {
  for (int i = 0; i < waveSize; i++) {
    createEnemy(createEntity("enemy"), waveStart + ((rand() % 1000 + 1) * i),
                rand() % 1000 + 1);
  }
}

void Rtype::GameMultiScene::setVelocity(std::string contentVelocity) {
  auto &PlayerIds = getRegistry().getComponents<RNGine::components::PlayerId>();
  auto &Velocitys = getRegistry().getComponents<RNGine::components::Velocity>();
  auto &Positions = getRegistry().getComponents<RNGine::components::Position>();
  int id = 0;
  float velocityX = 0.0;
  float velocityY = 0.0;
  float posX = 0.0;
  float posY = 0.0;

  std::istringstream iss(contentVelocity);
  char delimiter = ',';

  std::string token;
  int tokenIndex = 0;

  while (std::getline(iss, token, delimiter)) {
    if (tokenIndex == 4) {
      id = std::stoi(token);
    } else if (tokenIndex == 0) {
      velocityX = std::stof(token);
    } else if (tokenIndex == 1) {
      velocityY = std::stof(token);
    } else if (tokenIndex == 2) {
      posX = std::stof(token);
    } else if (tokenIndex == 3) {
      posY = std::stof(token);
    }
    tokenIndex++;
  }

  for (int i = 0; i < PlayerIds.size(); i++) {
    if (!PlayerIds[i].has_value() || !Velocitys[i].has_value() ||
        !Positions[i].has_value() || PlayerIds[i]->id != id || _ID == id)
      continue;
    Velocitys[i]->x = velocityX;
    Velocitys[i]->y = velocityY;
    Positions[i]->x = posX;
    Positions[i]->y = posY;
  }
}

void Rtype::GameMultiScene::makeShoot(std::string contentShoot) {
  auto &PlayerIds = getRegistry().getComponents<RNGine::components::PlayerId>();
  auto &Positions = getRegistry().getComponents<RNGine::components::Position>();
  auto &Sprites = getRegistry().getComponents<RNGine::components::Sprite>();
  auto &Sizes = getRegistry().getComponents<RNGine::components::Size>();
  auto &Shoots = getRegistry().getComponents<RNGine::components::Shoot>();
  auto &Velocities =
      getRegistry().getComponents<RNGine::components::Velocity>();
  int id = std::stoi(contentShoot);

  for (int i = 0; i < PlayerIds.size(); i++) {
    if (!PlayerIds[i].has_value() || PlayerIds[i]->id != id ||
        !Shoots[i].has_value() || !Positions[i].has_value() ||
        !Sprites[i].has_value() || !Sizes[i].has_value() ||
        !Velocities[i].has_value() || _ID == id)
      continue;
    auto shoot = createEntity("shoot");
    addComponent<RNGine::components::Position>(
        shoot,
        RNGine::components::Position::createPosition(
            Positions[i]->x + (Sprites[i]->sizeTileX * Sizes[i]->scaleX),
            Positions[i]->y + (Sprites[i]->sizeTileY * Sizes[i]->scaleY) / 2));
    addComponent<RNGine::components::Velocity>(
        shoot,
        RNGine::components::Velocity::createVelocity(
            Shoots[i]->speedX, Shoots[i]->speedY + Velocities[i]->y / 2));
    addComponent<RNGine::components::Sprite>(
        shoot, RNGine::components::Sprite::createSprite(
                   "./assets/ShootsAndPlayer.gif", false, 33, 22, 6, 1, 3));
    addComponent<RNGine::components::Size>(
        shoot, RNGine::components::Size::createSize(1, 1));
    addComponent(shoot, RNGine::components::Collider::createCollider(33, 22));
    addComponent(shoot, RNGine::components::MakeDamage::createMakeDamage(
                            Shoots[i]->power, true));
    addComponent(shoot, RNGine::components::Selfdestroy::createSelfDestroy(
                            1920, 1080 + 150, -150, -150));
  }
}

void Rtype::GameMultiScene::takeDamage(std::string contentShoot) {
  auto &PlayerIds = getRegistry().getComponents<RNGine::components::PlayerId>();
  auto &Attackables =
      getRegistry().getComponents<RNGine::components::Attackable>();
  int id = 0;
  int damages = 0;
  std::istringstream iss(contentShoot);
  char delimiter = ',';

  std::string token;
  int tokenIndex = 0;

  while (std::getline(iss, token, delimiter)) {
    if (tokenIndex == 4) {
      id = std::stoi(token);
    } else if (tokenIndex == 0) {
      damages = std::stof(token);
    } else if (tokenIndex == 1) {
      id = std::stoi(token);
    }
    tokenIndex++;
  }
  for (int i = 0; i < PlayerIds.size(); i++) {
    if (!PlayerIds[i].has_value() || PlayerIds[i]->id != id ||
        !Attackables[i].has_value() || _ID == id)
      continue;
    Attackables[i]->health = Attackables[i]->health - damages;
  }
}