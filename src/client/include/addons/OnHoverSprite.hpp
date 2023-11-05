/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_ADDONS_ONHOVERSPRITE_HPP_
#define _RTYPE_CLIENT_ADDONS_ONHOVERSPRITE_HPP_

#include <optional>

#include "RNGine/RNGine.hpp"
namespace r
{
#include "raylib.h"
}

#include "../components/RenderTexture.hpp"

namespace Client {
namespace Components {
struct OnHoverSprite {
  RenderTexture hoverSprite;
  bool isChanged = false;
  r::Vector4 hitbox = {0, 0, 0, 0};
  std::optional<RenderTexture> tmpSprite = std::make_optional<RenderTexture>();
};

void OnHoverSpriteSystem(RNGine::Core &core);
} // namespace Components
} // namespace Client

#endif