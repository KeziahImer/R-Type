/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_COMPONENTS_NUMBERLEVELS_HPP_
#define _RTYPE_CLIENT_COMPONENTS_NUMBERLEVELS_HPP_

#include "RNGine/RNGine.hpp"
namespace r
{
#include "raylib.h"
}

namespace Client {
namespace Components {
struct NumberLevel {
  int numberLevel = 0;
};
} // namespace Components
} // namespace Client

#endif