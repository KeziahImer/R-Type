/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Menu Scene
*/

#ifndef _RTYPE_GAME_SCENE_HPP_
#define _RTYPE_GAME_SCENE_HPP_

#include "SFML/Graphics/Color.hpp"
#include "rngine/Keys.hpp"
#include "rngine/Scene.hpp"
#include "rngine/components/Attackable.hpp"
#include "rngine/components/Clickable.hpp"
#include "rngine/components/Collider.hpp"
#include "rngine/components/EnemyShoot.hpp"
#include "rngine/components/Movable.hpp"
#include "rngine/components/Position.hpp"
#include "rngine/components/SelfDestroy.hpp"
#include "rngine/components/Shoot.hpp"
#include "rngine/components/Size.hpp"
#include "rngine/components/Sprite.hpp"
#include "rngine/components/Velocity.hpp"
#include "rngine/components/healthBar.hpp"
#include "rngine/components/text.hpp"
#include "rules/systems/Click.hpp"
#include "rules/systems/Engine.hpp"
#include "rules/systems/Physics.hpp"
#include "rules/systems/Shoots.hpp"
#include <utility>

#include <cstddef>

namespace Rtype {
class GameScene : public RNGine::Scene {
public:
  GameScene();

  void createBackground(RNGine::Entity e);
  void createPlayer(RNGine::Entity e);
  void createEnemy(RNGine::Entity e, float posX, float posY);
  void createScore(RNGine::Entity e);
  void createHealthBar(RNGine::Entity e, RNGine::Entity entity, float hp);
};
}; // namespace Rtype

#endif