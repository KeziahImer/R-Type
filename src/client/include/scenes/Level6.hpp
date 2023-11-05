/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype Level6
*/

#ifndef _RTYPE_CLIENT_SCENES_Level6_HPP_
#define _RTYPE_CLIENT_SCENES_Level6_HPP_

#include "Rtype/Rtype.hpp"
#include "Rtype/addons/EnemyFactory.hpp"

namespace Client {
namespace Scenes {

class Level6 : public Rtype::Core {
public:
  Level6(RNGine::Core &core);
  ~Level6() = default;
};
} // namespace Scenes
} // namespace Client

#endif