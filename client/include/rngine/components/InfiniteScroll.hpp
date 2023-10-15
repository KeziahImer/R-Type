/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Components
*/

#ifndef _RNGINE_COMPONENTS_SCROLL_HPP_
#define _RNGINE_COMPONENTS_SCROLL_HPP_
namespace RNGine {
namespace components {
struct InfiniteScroll {
  float switchValue;
  float respawnValue;

  static InfiniteScroll createInfiniteScroll(float switchValue,
                                             float respawnValue) {
    auto val = InfiniteScroll();
    val.switchValue = switchValue;
    val.respawnValue = respawnValue;
    return val;
  }
};
} // namespace components
} // namespace RNGine

#endif
