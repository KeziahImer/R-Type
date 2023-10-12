/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Components
*/

#ifndef _RNGINE_COMPONENTS_SELFDESTROY_HPP_
#define _RNGINE_COMPONENTS_SELFDESTROY_HPP_
namespace RNGine {
namespace components {
struct Selfdestroy {
  float MaxX;
  float MaxY;
  float MinX;
  float MinY;

  static Selfdestroy createSelfDestroy(float MaxX, float MaxY, float MinX,
                                       float MinY);
};
} // namespace components
} // namespace RNGine

#endif
