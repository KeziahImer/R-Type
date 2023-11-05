/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype Level5
*/

#ifndef _RTYPE_SERVER_SCENES_Level5_HPP_
#define _RTYPE_SERVER_SCENES_Level5_HPP_

#include "Rtype/Rtype.hpp"
#include "Rtype/addons/EnemyFactory.hpp"

namespace Server {
namespace Scenes {

class Level5 : public Rtype::Core {
public:
  Level5(RNGine::Core &core);
  ~Level5() = default;
};
} // namespace Scenes
} // namespace Server

#endif