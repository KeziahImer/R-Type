/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype engine
*/

#ifndef _RTYPE_ENGINE_COMPONENTS_TRANSFORM_HPP_
#define _RTYPE_ENGINE_COMPONENTS_TRANSFORM_HPP_

namespace RNGine {
namespace Components {
struct Transform {
  float x = 0;
  float y = 0;
  float rotation = 0;
  float scaleX = 1;
  float scaleY = 1;
};
}; // namespace Components
} // namespace RNGine

#endif