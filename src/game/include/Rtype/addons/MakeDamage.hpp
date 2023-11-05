/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RNGINE_COMPONENTS_MAKEDAMAGE_HPP_
#define _RNGINE_COMPONENTS_MAKEDAMAGE_HPP_

#include "RNGine/Core.hpp"
#include <variant>

using shootAnimationValue = std::variant<bool, std::pair<int, int>, RNGine::Core::Time>;

namespace RNGine {
namespace Components {
struct MakeDamage {
  float Damage;
  bool ally;
  RNGine::Scene::Entity father;
  std::string bulletSprite = "./assets/bullets.gif";
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
      {"frequence", (RNGine::Core::Time) 150}
  };
  bool printed = false;
};
} // namespace Components
} // namespace RNGine

#endif