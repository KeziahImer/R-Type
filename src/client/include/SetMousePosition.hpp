/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_SETMOUSEPOSITION_HPP_
#define _RTYPE_CLIENT_SETMOUSEPOSITION_HPP_

#include "RNGine/RNGine.hpp"
#include "raylib.h"

#include "components/MousePosition.hpp"

#include <map>

namespace Client {
void SetMousePosition(RNGine::Scene &scene);
} // namespace Client

#endif