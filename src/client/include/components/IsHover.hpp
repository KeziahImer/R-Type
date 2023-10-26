/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_COMPONENTS_ISHOVER_HPP_
#define _RTYPE_CLIENT_COMPONENTS_ISHOVER_HPP_

#include <optional>

#include "RNGine/RNGine.hpp"
#include "raylib.h"

#include "RenderTexture.hpp"

namespace Client {
namespace Components {
struct IsHover {
  bool isHover = false;
};

void IsHoverSystem(RNGine::Core &core);
} // namespace Components
} // namespace Client

#endif