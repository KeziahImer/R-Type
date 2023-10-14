/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Menu Scene
*/

#ifndef _RTYPE_MENU_SCENE_HPP_
#define _RTYPE_MENU_SCENE_HPP_

#include "Game.hpp"
#include "Lobby.hpp"
#include "SFML/Graphics/Color.hpp"
#include "rngine/Core.hpp"
#include "rngine/Scene.hpp"
#include "rngine/components/Clickable.hpp"
#include "rngine/components/Position.hpp"
#include "rngine/components/Size.hpp"
#include "rngine/components/Sprite.hpp"
#include "rules/systems/Click.hpp"
#include <cstddef>
#include <utility>

namespace Rtype {
class MenuScene : public RNGine::Scene {
public:
  MenuScene(RNGine::Core &core, Rtype::Network &network,
            boost::asio::io_context &ioContext);

  void createBackground(RNGine::Entity e);
  void createLogo(RNGine::Entity e);
  void createButton(RNGine::Entity e, std::string text,
                    std::function<void(void)> function, float posX, float posY,
                    float sizeX, float sizeY);

private:
  RNGine::Core &_core;
  Rtype::Network &_network;
  boost::asio::io_context &_ioContext;
};
}; // namespace Rtype

#endif