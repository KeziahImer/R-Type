/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RNGINE_COMPONENTS_MAKEDAMAGEBODY_HPP_
#define _RNGINE_COMPONENTS_MAKEDAMAGEBODY_HPP_
#include <variant>

namespace RNGine {
namespace Components {
struct MakeDamageBody {
  float Damage;
  bool ally;
  bool printed = false;
};
} // namespace Components
} // namespace RNGine

#endif