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
#include "rngine/components/Size.hpp"
#include "rngine/components/Sprite.hpp"

#include <cstddef>

namespace Rtype {
class MenuScene : public RNGine::Scene {
public:
  MenuScene() {
    setId("menu");
    createBackground(createEntity("background"));
  }

  void createBackground(RNGine::Entity e) {
    addComponent(
        e, RNGine::components::Sprite::createSprite(
               "./client/assets/backgroundSpace.jpg", false, 514, 360, 0, 0));
    addComponent(e, RNGine::components::Position::createPosition(0, 0));
    addComponent(e, RNGine::components::Size::createSize(3.73, 3));
  }
};
}; // namespace Rtype

#endif