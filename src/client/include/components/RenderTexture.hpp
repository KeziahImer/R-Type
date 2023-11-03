/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_COMPONENTS_RENDERTEXTURE_HPP_
#define _RTYPE_CLIENT_COMPONENTS_RENDERTEXTURE_HPP_

#include "RNGine/RNGine.hpp"
namespace r {
#include "raylib.h"
}

namespace Client {
namespace Components {
struct RenderTexture {
  std::string path;
  int z;
  r::Rectangle source;
  r::Rectangle dest;
  r::Vector2 origin;
  float rotation;
  bool useTransformPropreties = true;
  bool useHitboxPropreties = true;
};
} // namespace Components
} // namespace Client

#endif