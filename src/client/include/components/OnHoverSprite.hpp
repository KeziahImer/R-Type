/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_COMPONENTS_ONHOVERSPRITE_HPP_
#define _RTYPE_CLIENT_COMPONENTS_ONHOVERSPRITE_HPP_

#include <optional>

#include "RNGine/RNGine.hpp"
#include "raylib.h"

#include "RenderTexture.hpp"

namespace Client {
namespace Components {
struct OnHoverSprite {
  RenderTexture hoverSprite;
  bool isChanged = false;
  Vector4 hitbox = {0, 0, 0, 0};
  std::optional<RenderTexture> tmpSprite = std::make_optional<RenderTexture>();
};

void OnHoverSpriteSystem(RNGine::Core &core);
} // namespace Components
} // namespace Client

#endif