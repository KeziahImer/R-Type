/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_COMPONENTS_NUMBERPLAYERS_HPP_
#define _RTYPE_CLIENT_COMPONENTS_NUMBERPLAYERS_HPP_

#include "RNGine/RNGine.hpp"
namespace r
{
#include "raylib.h"
}

namespace Client {
namespace Components {
struct NumberPlayers {
  int numberPlayers = 0;
};
} // namespace Components
} // namespace Client

#endif