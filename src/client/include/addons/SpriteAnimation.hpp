/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_ADDONS_SPRITEANIMATION_HPP_
#define _RTYPE_CLIENT_ADDONS_SPRITEANIMATION_HPP_

#include <optional>

#include "RNGine/RNGine.hpp"
namespace r
{
#include "raylib.h"
}

#include "../components/RenderTexture.hpp"

namespace Client {
namespace Components {
struct SpriteAnimation {
  bool reverse;
  bool loop;
  bool multiple;
  bool finish;
  std::pair<int, int> start;
  std::pair<int, int> end;
  std::pair<int, int> lastFrame;
  RNGine::Core::Time frequence;
  RNGine::Core::Time lastUpdate = 0;
};

void SpriteAnimationSystem(RNGine::Core &core);
} // namespace Components
} // namespace Client

#endif