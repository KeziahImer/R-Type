/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_GAME_CORE_HPP_
#define _RTYPE_GAME_CORE_HPP_

#include "RNGine/RNGine.hpp"

namespace Rtype {
class Core : public RNGine::Scene {
public:
  Core() = default;
  ~Core() = default;

  void CreateShipFactory();
  void CreateEnemyFactory();
  void CreateCollisionFactory();
};
} // namespace Rtype

#endif