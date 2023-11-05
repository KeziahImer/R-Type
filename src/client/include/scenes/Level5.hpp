/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype Level5
*/

#ifndef _RTYPE_CLIENT_SCENES_Level5_HPP_
#define _RTYPE_CLIENT_SCENES_Level5_HPP_

#include "Rtype/Rtype.hpp"
#include "Rtype/addons/EnemyFactory.hpp"

namespace Client {
namespace Scenes {

class Level5 : public Rtype::Core {
public:
  Level5(RNGine::Core &core);
  ~Level5() = default;

  static void SetBackgroundTexture(RNGine::Core &core);

};
} // namespace Scenes
} // namespace Client

#endif