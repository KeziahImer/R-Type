/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype Level1
*/

#ifndef _RTYPE_SERVER_SCENES_LEVEL1_HPP_
#define _RTYPE_SERVER_SCENES_LEVEL1_HPP_

#include "RNGine/Core.hpp"
#include "Rtype/Rtype.hpp"
#include "Rtype/addons/EnemyFactory.hpp"
#include "Server.hpp"

namespace Server {
namespace Scenes {

class Level1 : public Rtype::Core {
public:
  Level1(RNGine::Core &core);
  ~Level1() = default;
};
} // namespace Scenes
} // namespace Server

#endif