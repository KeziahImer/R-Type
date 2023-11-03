/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_SCENES_LOBBY_HPP_
#define _RTYPE_CLIENT_SCENES_LOBBY_HPP_

#include "RNGine/RNGine.hpp"

namespace Client {
namespace Scenes {

class Lobby : public RNGine::Scene {
public:
  Lobby(RNGine::Core &core);
  ~Lobby() = default;

  void CreateMouse();

  void CreateButton(const std::string &id, const std::string &sprite,
                    float marginTop);

  static void OnClickButtonStart(RNGine::Core &core);

  static void OnClickButtonback(RNGine::Core &core);

  static void renderPlayers(RNGine::Core &core);

protected:
  int numberPlayers = 0;
};
} // namespace Scenes
} // namespace Client

#endif