/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Menu Scene
*/

#ifndef _RTYPE_GAMEMULTI_SCENE_HPP_
#define _RTYPE_GAMEMULTI_SCENE_HPP_

#include "../../../Network.hpp"
#include "SFML/Graphics/Color.hpp"
#include "rngine/Keys.hpp"
#include "rngine/Scene.hpp"
#include "rngine/components/Attackable.hpp"
#include "rngine/components/Clickable.hpp"
#include "rngine/components/Collider.hpp"
#include "rngine/components/EnemyShoot.hpp"
#include "rngine/components/InfiniteScroll.hpp"
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
class GameMultiScene : public RNGine::Scene {
public:
  GameMultiScene(int id, int playerNumber, Rtype::Network *network,
                 boost::asio::io_context &ioContext);

  void createBackground(RNGine::Entity e, float x, float y);
  void createPlayer(RNGine::Entity e, int id, Rtype::Network *network);
  void createAlly(RNGine::Entity e, int id);
  void createEnemy(RNGine::Entity e, float posX, float posY);
  void createScore(RNGine::Entity e);
  void createHealthBar(RNGine::Entity e, RNGine::Entity entity, float hp);
  void setVelocity(std::string contentVelocity);
  void makeShoot(std::string contentShoot);
  void createWave(int waveSize, int waveStart);

private:
  int _playersNbr = 0;
  int _ID = 0;
  Rtype::Network *_network;
  boost::asio::io_context &_ioContext;
};
}; // namespace Rtype

#endif