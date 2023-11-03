/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_SCENES_LEVELSELECT_HPP_
#define _RTYPE_CLIENT_SCENES_LEVELSELECT_HPP_

#include "RNGine/RNGine.hpp"

namespace Client {
namespace Scenes {

class LevelSelect : public RNGine::Scene {
public:
  LevelSelect(RNGine::Core &core);
  ~LevelSelect() = default;

  void CreateMouse();

  void CreateButton(const std::string &id, const std::string &sprite,
                    float marginTop);
  void CreateButtonLevel(int levelNumber);
  static void OnClickButtonStart(RNGine::Core &core);
  static void OnClickButtonLevel(RNGine::Core &core);

  static void OnClickButtonback(RNGine::Core &core);
  void renderLevelNumbers(RNGine::Core &core);

protected:
  int numberPlayers = 0;
};
} // namespace Scenes
} // namespace Client

#endif