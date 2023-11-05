/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype Level4
*/

#ifndef _RTYPE_SERVER_SCENES_Level4_HPP_
#define _RTYPE_SERVER_SCENES_Level4_HPP_

#include "Rtype/Rtype.hpp"
#include "Rtype/addons/EnemyFactory.hpp"

namespace Server {
namespace Scenes {

class Level4 : public Rtype::Core {
public:
  Level4(RNGine::Core &core);
  ~Level4() = default;
};
} // namespace Scenes
} // namespace Server

#endif