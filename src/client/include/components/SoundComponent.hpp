/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_COMPONENTS_SOUND_HPP_
#define _RTYPE_CLIENT_COMPONENTS_SOUND_HPP_

#include "RNGine/RNGine.hpp"
namespace r
{
#include "raylib.h"
}

namespace Client {
namespace Components {
struct SoundComponent {
  std::string path;
  bool play;
  bool loop;
  bool stop;
  float volume = 100;
};
} // namespace Components
} // namespace Client

#endif
