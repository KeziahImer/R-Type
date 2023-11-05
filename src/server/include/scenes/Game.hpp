/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_SERVER_SCENES_GAME_HPP_
#define _RTYPE_SERVER_SCENES_GAME_HPP_

#include "Rtype/Rtype.hpp"
#include "Rtype/addons/CollisionFactory.hpp"
#include "Rtype/addons/EnemyFactory.hpp"
#include "Server.hpp"

namespace Server {
namespace Scenes {

class Game : public Rtype::Core {
public:
  Game(RNGine::Core &core);
  ~Game() = default;

  static void CreateMainShip(RNGine::Core &core);
  static void CreateEnemySystem(RNGine::Core &core);
  static void MoveShip(RNGine::Core &core);
};
} // namespace Scenes
} // namespace Server

#endif