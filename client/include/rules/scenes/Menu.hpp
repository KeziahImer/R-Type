/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Menu Scene
*/

#ifndef _RTYPE_MENU_SCENE_HPP_
#define _RTYPE_MENU_SCENE_HPP_

#include "rngine/Scene.hpp"
#include "rngine/components/Position.hpp"
#include "rngine/components/SelfDestroy.hpp"
#include "rngine/components/Size.hpp"
#include "rngine/components/Sprite.hpp"
#include "rngine/components/Velocity.hpp"

#include <cstddef>

namespace Rtype {
class MenuScene : public RNGine::Scene {
public:
  MenuScene();

  void createBackground(RNGine::Entity e);
  void createPlayer(RNGine::Entity e);
  void createEnemy(RNGine::Entity e, float posX, float posY);
  void createScore(RNGine::Entity e);
};
}; // namespace Rtype

#endif