/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_ADDONS_CREATESHIPS_HPP_
#define _RTYPE_CLIENT_ADDONS_CREATESHIPS_HPP_
#include "RNGine/RNGine.hpp"
#include "Rtype/addons/ShipFactory.hpp"

namespace Rtype {
namespace Addons {
struct CreateShips {
  int nbrPlayers = 0;
};

void CreateShipsSystem(RNGine::Core &core);
} // namespace Components
} // namespace Client

#endif