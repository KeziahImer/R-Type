#include "rngine/Keys.hpp"
#include "rngine/Registry.hpp"
#include "rngine/components/Attackable.hpp"
#include "rngine/components/MakeDamage.hpp"
#include "rngine/components/SelfDestroy.hpp"
#include "rngine/components/Shoot.hpp"
#include "rngine/components/Size.hpp"
#include "rngine/components/Sprite.hpp"
#include "rngine/components/Velocity.hpp"
#include "rules/systems/Physics.hpp"

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
  auto &Attackables = registry.getComponents<RNGine::components::Attackable>();

  for (size_t i = 0; i < Colliders.size(); i++) {
    for (size_t x = 0; x < MakeDamages.size(); x++) {
      if (!Colliders[i].has_value() || !MakeDamages[x].has_value() ||
          !Attackables[i].has_value() || !Positions[i].has_value())
        continue;
      if (checkCollision(Colliders[i], Colliders[x], Positions[i],
                         Positions[x])) {
        Attackables[i]->health =
            Attackables[i]->health - MakeDamages[x]->Damage;
      }
    }
  }
};

RNGine::Registry::System ShootSystem = [](RNGine::Registry &registry) {
  RNGine::SparseArray<RNGine::components::Shoot> &Shoots =
      registry.getComponents<RNGine::components::Shoot>();
  RNGine::SparseArray<RNGine::components::Position> &Positions =
      registry.getComponents<RNGine::components::Position>();
  std::map<enum RNGine::Key, bool> inputs = registry.inputs;

  for (size_t i = 0; i < Shoots.size(); i++) {
    if (!Shoots[i].has_value())
      continue;
    for (auto inputPress : inputs) {
      if ((inputPress.first == Shoots[i]->Input) && inputPress.second) {
        auto time = std::chrono::duration_cast<std::chrono::milliseconds>(
                        std::chrono::system_clock::now().time_since_epoch())
                        .count();
        if (time - Shoots[i]->lastShoot > Shoots[i]->timeMillisecond) {
          Shoots[i]->lastShoot = time;
          RNGine::Entity shoot = registry.createEntity("shoot");
          registry.addComponent<RNGine::components::Position>(
              shoot, RNGine::components::Position::createPosition(
                         Positions[i]->x, Positions[i]->y));
          registry.addComponent<RNGine::components::Velocity>(
              shoot, RNGine::components::Velocity::createVelocity(
                         Shoots[i]->speedX, Shoots[i]->speedY));
          registry.addComponent<RNGine::components::Sprite>(
              shoot,
              RNGine::components::Sprite::createSprite(
                  "./assets/ShootsAndPlayer.gif", false, 33, 22, 6, 1, 2));
          registry.addComponent<RNGine::components::Size>(
              shoot, RNGine::components::Size::createSize(1, 1));
          registry.addComponent(
              shoot, RNGine::components::Collider::createCollider(33, 22));
          registry.addComponent(
              shoot, RNGine::components::MakeDamage::createMakeDamage(
                         Shoots[i]->power));
          registry.addComponent(
              shoot, RNGine::components::Selfdestroy::createSelfDestroy(
                         1920 + 150, 1080 + 150, -150, -150));
        }
      }
    }
  }
};

RNGine::Registry::System CheckHealth = [](RNGine::Registry &registry) {
  RNGine::SparseArray<RNGine::components::Attackable> &Attackables =
      registry.getComponents<RNGine::components::Attackable>();

  for (size_t i = 0; i < Attackables.size(); i++) {
    if (!Attackables[i].has_value())
      continue;
    if (Attackables[i]->health <= 0) {
      registry.removeEntity(i);
    }
  }
};

namespace Rtype {
RNGine::Registry::SystemBundle shootsSystems = {ShootCollisionSystem,
                                                ShootSystem, CheckHealth};
}
