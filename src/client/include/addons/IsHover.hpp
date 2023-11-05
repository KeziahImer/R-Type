/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_ADDONS_ISHOVER_HPP_
#define _RTYPE_CLIENT_ADDONS_ISHOVER_HPP_

#include <optional>

#include "RNGine/RNGine.hpp"
namespace r
{
#include "raylib.h"
}

#include "../components/RenderTexture.hpp"

namespace Client {
namespace Components {
struct IsHover {
  bool isHover = false;
};

void IsHoverSystem(RNGine::Core &core);
} // namespace Components
} // namespace Client

#endif