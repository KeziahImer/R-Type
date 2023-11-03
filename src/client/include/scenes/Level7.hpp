/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype Level7
*/

#ifndef _RTYPE_CLIENT_SCENES_Level7_HPP_
#define _RTYPE_CLIENT_SCENES_Level7_HPP_

#include "Rtype/Rtype.hpp"
#include "Rtype/addons/EnemyFactory.hpp"

namespace Client {
namespace Scenes {

class Level7 : public Rtype::Core {
public:
  Level7(RNGine::Core &core);
  ~Level7() = default;
};
} // namespace Scenes
} // namespace Client

#endif