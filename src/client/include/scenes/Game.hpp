/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_SCENES_GAME_HPP_
#define _RTYPE_CLIENT_SCENES_GAME_HPP_

#include "Rtype/Rtype.hpp"
#include "Rtype/addons/CollisionFactory.hpp"
#include "Rtype/addons/EnemyFactory.hpp"

namespace Client {
namespace Scenes {

class Game : public Rtype::Core {
public:
  Game(RNGine::Core &core);
  ~Game() = default;

  static void CreateMainShip(RNGine::Core &core);
  static void CreateEnemySystem(RNGine::Core &core);
  static void ApplyShipTexture(RNGine::Core &core);
  static void ApplyEnemyTexture(RNGine::Core &core,
                                RNGine::Scene::Entity &enemy,
                                std::map<std::string, Value> &enemyInfo);
  static void
  ApplyCollisionTexture(RNGine::Core &core, RNGine::Scene::Entity &collision,
                        std::map<std::string, ValueCollision> &collisionInfo);
  static void MoveShip(RNGine::Core &core);

  static void SetBulletsTexture(RNGine::Core &core);

  static void SetBackgroundTexture(RNGine::Core &core);

  static void SetWeaponSlotTexture(RNGine::Core &core);

  static void SetPowerupInventoryTexture(RNGine::Core &core);

  static void LeaveScene(RNGine::Core &core);
};
} // namespace Scenes
} // namespace Client

#endif