/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Menu Scene
*/

#ifndef _RTYPE_SYSTEMS_PHYSICS_HPP_
#define _RTYPE_SYSTEMS_PHYSICS_HPP_

#include "rngine/Keys.hpp"
#include "rngine/Registry.hpp"
#include "rngine/Scene.hpp"
#include "rngine/components/Collider.hpp"
#include "rngine/components/Movable.hpp"
#include "rngine/components/Position.hpp"
#include "rngine/components/SelfDestroy.hpp"
#include "rngine/components/Size.hpp"
#include "rngine/components/Sprite.hpp"
#include "rngine/components/Velocity.hpp"

#include <cstddef>

namespace Rtype {

extern RNGine::Registry::SystemBundle physicsSystems;
} // namespace Rtype
#endif