/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype engine
*/

#ifndef _RTYPE_ENGINE_COMPONENTS_HITBOX_HPP_
#define _RTYPE_ENGINE_COMPONENTS_HITBOX_HPP_

namespace RNGine {
namespace Components {
struct Hitbox {
  float width = 0;
  float height = 0;

  float originX = 0;
  float originY = 0;
};
}; // namespace Components
} // namespace RNGine

#endif