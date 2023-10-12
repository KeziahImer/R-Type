/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Menu Scene
*/

#ifndef _RTYPE_MENU_SCENE_HPP_
#define _RTYPE_MENU_SCENE_HPP_

#include "SFML/Graphics/Color.hpp"
#include "rngine/Core.hpp"
#include "rngine/Scene.hpp"
#include "rngine/components/Clickable.hpp"
#include "rngine/components/Position.hpp"
#include "rngine/components/Size.hpp"
#include "rngine/components/Sprite.hpp"
#include "rules/systems/Click.hpp"
#include <utility>

#include <cstddef>

namespace Rtype {
class MenuScene : public RNGine::Scene {
public:
  MenuScene(RNGine::Core &core);

  void createBackground(RNGine::Entity e);
  void createButton(RNGine::Entity e, std::string text,
                    std::function<void(void)> function, float posX, float posY,
                    float sizeX, float sizeY);
};
}; // namespace Rtype

#endif