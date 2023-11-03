/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_TEXTRENDERER_HPP_
#define _RTYPE_CLIENT_TEXTRENDERER_HPP_

#include "RNGine/RNGine.hpp"
namespace r
{
#include "raylib.h"
}

#include <map>

namespace Client {
class TextRenderer {
public:
  TextRenderer() = default;
  ~TextRenderer() = default;

  void UpdateTexts(RNGine::Scene &scene);

private:
  std::map<std::string, r::Font> _fonts;
};
} // namespace Client

#endif
