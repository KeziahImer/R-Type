/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_ADDONS_ENEMYSHOOT_HPP_
#define _RTYPE_CLIENT_ADDONS_ENEMYSHOOT_HPP_

#include <optional>
#include <variant>

#include "RNGine/RNGine.hpp"
#include "RNGine/addons/Velocity.hpp"

using shootAnimationValue =
    std::variant<bool, std::pair<int, int>, RNGine::Core::Time>;

namespace RNGine {
namespace Addons {
struct EnemyShoot {
  RNGine::Core::Time frequence = 1000;
  RNGine::Core::Time lastUpdate = 0;
  RNGine::Addons::Velocity velocity = {-1200.0f, 0.0f};
  std::pair<float, float> destroyPosition = {-100.0f, 2020.0f};
  std::pair<float, float> offset = {-32 * 2.0f, 0.0f};
  std::pair<float, float> scale = {2.0f, 2.0f};
  RNGine::Components::Hitbox hitbox = {32 * 2, 10 * 2, 0, 0};
  std::string bulletSprite = "./assets/bullets.gif";
  std::pair<bool, RNGine::Addons::CollisionAction> colliderShoot = {
      false, RNGine::Addons::CollisionAction::None};
  std::pair<float, float> sourceFirst = {33 * 4.0f, 17.0f};
  std::pair<float, float> sourceSecond = {33.0f, 33.0f};
  std::string shootSound = "./assets/sounds/bullet.wav";
  float shootSoundVolume = 50;
  std::map<std::string, shootAnimationValue> shootAnimationValue = {
      {"reverse", false},
      {"loop", false},
      {"multiple", false},
      {"finish", false},
      {"start", std::pair<int, int>(4, 0)},
      {"end", std::pair<int, int>(7, 0)},
      {"lastFrame", std::pair<int, int>(7, 0)},
      {"frequence", (RNGine::Core::Time)150}};
};

void EnemyShootSystem(RNGine::Core &core);
} // namespace Addons
} // namespace RNGine

#endif