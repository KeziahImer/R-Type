/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Components
*/

#ifndef _RNGINE_COMPONENTS_NETWORKED_HPP_
#define _RNGINE_COMPONENTS_NETWORKED_HPP_
#include "../../../Network.hpp"
#include "SFML/Graphics/Color.hpp"
#include "text.hpp"
#include <functional>
#include <string>
namespace RNGine {
namespace components {
struct Networked {
  Rtype::Network *network;

  static Networked createNetworked(Rtype::Network *network) {
    auto val = Networked();
    val.network = network;
    return val;
  }
};
} // namespace components
} // namespace RNGine

#endif
