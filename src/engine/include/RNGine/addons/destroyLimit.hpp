/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_ADDONS_LIMITDESTROY_HPP_
#define _RTYPE_CLIENT_ADDONS_LIMITDESTROY_HPP_

#include <optional>

#include "RNGine/RNGine.hpp"

namespace RNGine {
namespace Addons {
struct destroyLimit {
  float minx;
  float maxx;
};

void checkLimitSystem(RNGine::Core &core);
} // namespace Addons
} // namespace RNGine

#endif