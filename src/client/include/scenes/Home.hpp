/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_SCENES_HOME_HPP_
#define _RTYPE_CLIENT_SCENES_HOME_HPP_

#include "RNGine/Core.hpp"
#include "RNGine/RNGine.hpp"

namespace Client {
namespace Scenes {

class Home : public RNGine::Scene {
public:
  Home(RNGine::Core &core);
  ~Home() = default;

  void CreateMouse();

  void CreateTitle();

  void CreateButton(const std::string &id, const std::string &sprite,
                    float marginTop);

  static void TrackMousePositionSystem(RNGine::Core &core);

  static void OnClickButtonSolo(RNGine::Core &core);
  static void OnClickButtonMulti(RNGine::Core &core);
  static void SetBackgroundTextureMenu(RNGine::Core &core);
};
} // namespace Scenes
} // namespace Client

#endif