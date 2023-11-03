/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_SCENES_VICTORY_HPP_
#define _RTYPE_CLIENT_SCENES_VICTORY_HPP_

#include "RNGine/RNGine.hpp"

namespace Client {
namespace Scenes {

class Victory : public RNGine::Scene {
public:
  Victory(RNGine::Core &core);
  ~Victory() = default;

  void CreateMouse();

  void CreateButton(const std::string &id, const std::string &sprite,
                    float marginTop);

  static void OnClickButtonRetry(RNGine::Core &core);

  static void OnClickButtonBackHome(RNGine::Core &core);

  static void renderVictory(RNGine::Core &core);

protected:
  int numberPlayers = 0;
};
} // namespace Scenes
} // namespace Client

#endif