/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype Level2
*/

#ifndef _RTYPE_SERVER_SCENES_Level2_HPP_
#define _RTYPE_SERVER_SCENES_Level2_HPP_

#include "Rtype/Rtype.hpp"
#include "Rtype/addons/EnemyFactory.hpp"

namespace Server {
namespace Scenes {

class Level2 : public Rtype::Core {
public:
  Level2(RNGine::Core &core);
  ~Level2() = default;
};
} // namespace Scenes
} // namespace Server

#endif