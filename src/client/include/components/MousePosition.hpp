/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_COMPONENTS_MOUSEPOSITION_HPP_
#define _RTYPE_CLIENT_COMPONENTS_MOUSEPOSITION_HPP_

#include "RNGine/RNGine.hpp"
namespace r {
#include "raylib.h"
}

namespace Client {
namespace Components {
struct MousePosition {
  r::Vector2 position = {0, 0};
  bool right_click = false;
  bool left_click = false;
};
} // namespace Components
} // namespace Client

#endif