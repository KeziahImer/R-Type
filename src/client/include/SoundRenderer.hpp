/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_SOUNDRENDERER_HPP_
#define _RTYPE_CLIENT_SOUNDRENDERER_HPP_

#include "RNGine/RNGine.hpp"
namespace r
{
#include "raylib.h"
}

#include "components/SoundComponent.hpp"

#include <map>

namespace Client {
class SoundRenderer {
public:
  SoundRenderer() = default;
  ~SoundRenderer() = default;

  void UpdateSounds(RNGine::Scene &scene);

private:
  std::map<std::string, r::Sound> _sounds;
};
} // namespace Client

#endif