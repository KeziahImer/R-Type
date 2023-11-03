/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_ADDONS_SHIPANIMATION_HPP_
#define _RTYPE_CLIENT_ADDONS_SHIPANIMATION_HPP_

#include <optional>

#include "RNGine/RNGine.hpp"
namespace r
{
#include "raylib.h"
}
#include "Rtype/Rtype.hpp"

#include "../components/RenderTexture.hpp"

namespace Client {
namespace Addons {
struct ShipAnimation {
  enum CurrentAction { None, Up, Down };
  CurrentAction lastAction;
};

void ShipAnimationSystem(RNGine::Core &core);
} // namespace Components
} // namespace Client

#endif