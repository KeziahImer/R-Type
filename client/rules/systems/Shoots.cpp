#include "rules/systems/Shoots.hpp"
#include "rngine/components/Movable.hpp"
#include "rngine/components/Networked.hpp"
#include "rngine/components/PlayerId.hpp"
#include "rngine/components/text.hpp"
#include "server/Network/Network.hpp"
#include <string>

bool checkCollision(std::optional<RNGine::components::Collider> collisionA,
                    std::optional<RNGine::components::Collider> collisionB,
                    std::optional<RNGine::components::Position> positionA,
                    std::optional<RNGine::components::Position> positionB) {

  float leftA = positionA->x;
  float rightA = leftA + collisionA->x;
  float topA = positionA->y;
  float bottomA = topA + collisionA->y;

  float leftB = positionB->x;
  float rightB = leftB + collisionB->x;
  float topB = positionB->y;
  float bottomB = topB + collisionB->y;

  // Vérifiez s'il y a intersection entre les deux rectangles
  if (rightA >= leftB && leftA <= rightB && bottomA >= topB &&
      topA <= bottomB) {
    return true; // Collision détectée
  }

  return false; // Pas de collision
}

RNGine::Registry::System ShootCollisionSystem = [](RNGine::Registry &registry) {
  // Obtenez toutes les entités avec le composant de collision
  auto &Colliders = registry.getComponents<RNGine::components::Collider>();
  auto &MakeDamages = registry.getComponents<RNGine::components::MakeDamage>();
  RNGine::SparseArray<RNGine::components::Position> &Positions =
      registry.getComponents<RNGine::components::Position>();
  RNGine::SparseArray<RNGine::components::Movable> &Movables =
      registry.getComponents<RNGine::components::Movable>();
  RNGine::SparseArray<RNGine::components::Networked> &Networkeds =
      registry.getComponents<RNGine::components::Networked>();
  RNGine::SparseArray<RNGine::components::PlayerId> &PlayerIds =
      registry.getComponents<RNGine::components::PlayerId>();
  auto &Attackables = registry.getComponents<RNGine::components::Attackable>();

  for (size_t i = 0; i < Colliders.size(); i++) {
    for (size_t x = 0; x < MakeDamages.size(); x++) {
      if (!Colliders[i].has_value() || !MakeDamages[x].has_value() ||
          !Attackables[i].has_value() || !Positions[i].has_value())
        continue;
      if (checkCollision(Colliders[i], Colliders[x], Positions[i],
                         Positions[x])) {
        if (Attackables[i]->ally == MakeDamages[x]->ally)
          continue;
        if (!Attackables[i]->_Attackable)
          continue;
        if (!Movables[i].has_value() && Attackables[i]->ally &&
            Networkeds[i].has_value()) {
          continue;
        }
        Attackables[i]->health =
            Attackables[i]->health - MakeDamages[x]->Damage;
        Attackables[i]->_Attackable = false;
        Attackables[i]->lastShoot =
            std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch())
                .count();
        if (Movables[i].has_value() && Networkeds[i].has_value() &&
            PlayerIds[i].has_value()) {
          std::string commandContent = std::to_string(Attackables[i]->health) +
                                       "," + std::to_string(PlayerIds[i]->id);
          Networkeds[i]->network->sendRequest(DAMAGE, NONE,
                                              commandContent.c_str());
        }
      }
    }
  }
};

RNGine::Registry::System ShootSystem = [](RNGine::Registry &registry) {
  RNGine::SparseArray<RNGine::components::Shoot> &Shoots =
      registry.getComponents<RNGine::components::Shoot>();
  RNGine::SparseArray<RNGine::components::Position> &Positions =
      registry.getComponents<RNGine::components::Position>();
  RNGine::SparseArray<RNGine::components::Sprite> &Sprites =
      registry.getComponents<RNGine::components::Sprite>();
  RNGine::SparseArray<RNGine::components::Size> &Sizes =
      registry.getComponents<RNGine::components::Size>();
  RNGine::SparseArray<RNGine::components::Velocity> &Velocities =
      registry.getComponents<RNGine::components::Velocity>();
  RNGine::SparseArray<RNGine::components::Networked> &Networkeds =
      registry.getComponents<RNGine::components::Networked>();
  RNGine::SparseArray<RNGine::components::PlayerId> &PlayerIds =
      registry.getComponents<RNGine::components::PlayerId>();
  std::map<enum RNGine::Key, bool> inputs = registry.inputs;

  for (size_t i = 0; i < Shoots.size(); i++) {
    if (!Shoots[i].has_value() || !Positions[i].has_value() ||
        !Sprites[i].has_value() || !Sizes[i].has_value() ||
        !Velocities[i].has_value())
      continue;
    for (auto inputPress : inputs) {
      if (Shoots[i]->Input == RNGine::Delete)
        continue;
      if ((inputPress.first == Shoots[i]->Input) && inputPress.second) {
        auto time = std::chrono::duration_cast<std::chrono::milliseconds>(
                        std::chrono::system_clock::now().time_since_epoch())
                        .count();
        if (time - Shoots[i]->lastShoot > Shoots[i]->timeMillisecond) {
          if (Networkeds[i].has_value() && PlayerIds[i].has_value()) {
            std::string commandContent = std::to_string(PlayerIds[i]->id);
            std::cout << "SHOOT ID: " << commandContent << std::endl;
            Networkeds[i]->network->sendRequest(SHOOT, NONE,
                                                commandContent.c_str());
          }
          Shoots[i]->lastShoot = time;
          RNGine::Entity shoot = registry.createEntity("shoot");
          registry.addComponent<RNGine::components::Position>(
              shoot,
              RNGine::components::Position::createPosition(
                  Positions[i]->x + (Sprites[i]->sizeTileX * Sizes[i]->scaleX),
                  Positions[i]->y +
                      (Sprites[i]->sizeTileY * Sizes[i]->scaleY) / 2));
          registry.addComponent<RNGine::components::Velocity>(
              shoot,
              RNGine::components::Velocity::createVelocity(
                  Shoots[i]->speedX, Shoots[i]->speedY + Velocities[i]->y / 2));
          registry.addComponent<RNGine::components::Sprite>(
              shoot,
              RNGine::components::Sprite::createSprite(
                  "./assets/ShootsAndPlayer.gif", false, 33, 22, 6, 1, 3));
          registry.addComponent<RNGine::components::Size>(
              shoot, RNGine::components::Size::createSize(1, 1));
          registry.addComponent(
              shoot, RNGine::components::Collider::createCollider(33, 22));
          registry.addComponent(
              shoot, RNGine::components::MakeDamage::createMakeDamage(
                         Shoots[i]->power, true));
          registry.addComponent(
              shoot, RNGine::components::Selfdestroy::createSelfDestroy(
                         1920, 1080 + 150, -150, -150));
        }
      }
    }
  }
};

RNGine::Registry::System EnemyShoot = [](RNGine::Registry &registry) {
  RNGine::SparseArray<RNGine::components::Position> &Positions =
      registry.getComponents<RNGine::components::Position>();
  RNGine::SparseArray<RNGine::components::Sprite> &Sprites =
      registry.getComponents<RNGine::components::Sprite>();
  RNGine::SparseArray<RNGine::components::Size> &Sizes =
      registry.getComponents<RNGine::components::Size>();
  RNGine::SparseArray<RNGine::components::Velocity> &Velocities =
      registry.getComponents<RNGine::components::Velocity>();
  RNGine::SparseArray<RNGine::components::EnemyShoot> &EnemyShoots =
      registry.getComponents<RNGine::components::EnemyShoot>();
  std::map<enum RNGine::Key, bool> inputs = registry.inputs;

  for (size_t i = 0; i < EnemyShoots.size(); i++) {
    if (!EnemyShoots[i].has_value() || !Positions[i].has_value() ||
        !Sprites[i].has_value() || !Sizes[i].has_value() ||
        !Velocities[i].has_value())
      continue;
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::system_clock::now().time_since_epoch())
                    .count();
    if (time - EnemyShoots[i]->lastShoot > EnemyShoots[i]->timeMillisecond) {
      EnemyShoots[i]->lastShoot = time;
      RNGine::Entity shoot = registry.createEntity("EnemyShoot");
      registry.addComponent<RNGine::components::Position>(
          shoot, RNGine::components::Position::createPosition(
                     Positions[i]->x - 33,
                     Positions[i]->y +
                         (Sprites[i]->sizeTileY * Sizes[i]->scaleY) / 2));
      registry.addComponent<RNGine::components::Velocity>(
          shoot, RNGine::components::Velocity::createVelocity(
                     EnemyShoots[i]->speedX,
                     EnemyShoots[i]->speedY + Velocities[i]->y / 2));
      registry.addComponent<RNGine::components::Sprite>(
          shoot, RNGine::components::Sprite::createSprite(
                     "./assets/ShootsAndPlayer.gif", true, 33, 22, 6, 1, 3));
      registry.addComponent<RNGine::components::Size>(
          shoot, RNGine::components::Size::createSize(1, 1));
      registry.addComponent(
          shoot, RNGine::components::Collider::createCollider(33, 22));
      registry.addComponent(shoot,
                            RNGine::components::MakeDamage::createMakeDamage(
                                EnemyShoots[i]->power, false));
      registry.addComponent(shoot,
                            RNGine::components::Selfdestroy::createSelfDestroy(
                                1920, 1080 + 150, -150, -150));
    }
  }
};

RNGine::Registry::System CheckInvisibility = [](RNGine::Registry &registry) {
  // Obtenez toutes les entités avec le composant de collision
  auto &Colliders = registry.getComponents<RNGine::components::Collider>();
  auto &MakeDamages = registry.getComponents<RNGine::components::MakeDamage>();
  RNGine::SparseArray<RNGine::components::Position> &Positions =
      registry.getComponents<RNGine::components::Position>();
  auto &Attackables = registry.getComponents<RNGine::components::Attackable>();

  for (size_t i = 0; i < Attackables.size(); i++) {
    if (!Attackables[i].has_value())
      continue;
    if (std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch())
                .count() -
            Attackables[i]->lastShoot >
        Attackables[i]->invinsibilityTime) {
      Attackables[i]->_Attackable = true;
      Attackables[i]->lastShoot =
          std::chrono::duration_cast<std::chrono::milliseconds>(
              std::chrono::system_clock::now().time_since_epoch())
              .count();
    }
  }
};

namespace Rtype {
RNGine::Registry::SystemBundle shootsSystems = {
    ShootCollisionSystem, ShootSystem, EnemyShoot, CheckInvisibility};
}
