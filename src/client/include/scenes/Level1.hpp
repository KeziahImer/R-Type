/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype Level1
*/

#ifndef _RTYPE_CLIENT_SCENES_LEVEL1_HPP_
#define _RTYPE_CLIENT_SCENES_LEVEL1_HPP_

#include "RNGine/Core.hpp"
#include "Rtype/Rtype.hpp"
#include "Rtype/addons/EnemyFactory.hpp"

namespace Client {
namespace Scenes {

class Level1 : public Rtype::Core {
public:
  Level1(RNGine::Core &core);
  ~Level1() = default;

  static void SetBackgroundTexture(RNGine::Core &core);
};
} // namespace Scenes
} // namespace Client

#endif