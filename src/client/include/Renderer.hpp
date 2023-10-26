/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_RENDERER_HPP_
#define _RTYPE_CLIENT_RENDERER_HPP_

#include "RNGine/RNGine.hpp"
#include "raylib.h"

#include "components/RenderTexture.hpp"

#include <map>

namespace Client {
class Renderer {
public:
  Renderer() = default;
  ~Renderer() = default;

  void RenderSprites(RNGine::Scene &scene);

  void UpdateSpriteWithTransform(Client::Components::RenderTexture &sprite,
                                 RNGine::Components::Transform &transform);

  void UpdateSpriteWithHitbox(Client::Components::RenderTexture &sprite,
                              RNGine::Components::Hitbox &hitbox);

  static bool SortSpritesByZ(const Client::Components::RenderTexture &a,
                             const Client::Components::RenderTexture &b);

private:
  std::map<std::string, Texture2D> _textures;
};
} // namespace Client

#endif