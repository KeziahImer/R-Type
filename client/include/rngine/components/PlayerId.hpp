/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Components
*/

#ifndef _RNGINE_COMPONENTS_PLAYERID_HPP_
#define _RNGINE_COMPONENTS_PLAYERID_HPP_
#include <chrono>
namespace RNGine {
namespace components {
struct PlayerId {
  int id;

  static PlayerId createPlayerId(int id) {
    auto val = PlayerId();
    val.id = id;
    return val;
  }
};
} // namespace components
} // namespace RNGine

#endif
