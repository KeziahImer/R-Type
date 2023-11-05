/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype Level3
*/

#ifndef _RTYPE_CLIENT_SCENES_Level3_HPP_
#define _RTYPE_CLIENT_SCENES_Level3_HPP_

#include "Rtype/Rtype.hpp"
#include "Rtype/addons/EnemyFactory.hpp"

namespace Client {
namespace Scenes {

class Level3 : public Rtype::Core {
public:
  Level3(RNGine::Core &core);
  ~Level3() = default;
};
} // namespace Scenes
} // namespace Client

#endif