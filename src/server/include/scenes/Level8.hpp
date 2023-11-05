/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype Level8
*/

#ifndef _RTYPE_SERVER_SCENES_Level8_HPP_
#define _RTYPE_SERVER_SCENES_Level8_HPP_

#include "Rtype/Rtype.hpp"
#include "Rtype/addons/EnemyFactory.hpp"

namespace Server {
namespace Scenes {

class Level8 : public Rtype::Core {
public:
  Level8(RNGine::Core &core);
  ~Level8() = default;
};
} // namespace Scenes
} // namespace Server

#endif