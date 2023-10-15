/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Menu Scene
*/

#ifndef _RTYPE_MENU_LOBBY_HPP_
#define _RTYPE_MENU_LOBBY_HPP_

#include "../../../Network.hpp"
#include "Game.hpp"
#include "SFML/Graphics/Color.hpp"
#include "rngine/Core.hpp"
#include "rngine/Scene.hpp"
#include "rngine/components/Clickable.hpp"
#include "rngine/components/InfiniteScroll.hpp"
#include "rngine/components/Position.hpp"
#include "rngine/components/Size.hpp"
#include "rngine/components/Sprite.hpp"
#include "rules/systems/Click.hpp"
#include <utility>

#include <cstddef>

namespace Rtype {
class LobbyScene : public RNGine::Scene {
public:
  LobbyScene(RNGine::Core *core, Rtype::Network &network,
             boost::asio::io_context &ioContext);

  void createBackground(RNGine::Entity e, float x, float y);
  void createButton(RNGine::Entity e, std::string text,
                    std::function<void(void)> function, float posX, float posY,
                    float sizeX, float sizeY);
  void createTexte(RNGine::Entity e, std::string text, int CharacterSize);
  void setNumberPlayers(int nbrPLayers);
  void setIDPlayer(int id);
  void startGame(size_t index, RNGine::Core *core);
  void initNetwork();

private:
  int _playersNbr = 0;
  int _ID = 0;
  RNGine::Core *_core;
  Rtype::Network &_network;
  boost::asio::io_context &_ioContext;
};
}; // namespace Rtype

#endif