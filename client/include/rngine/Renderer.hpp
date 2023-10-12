/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Renderer
*/
#ifndef _RNGINE_RENDERER_HPP_
#define _RNGINE_RENDERER_HPP_

#include "./Registry.hpp"
#include "./components/Position.hpp"
#include "./components/Size.hpp"
#include "./components/Sprite.hpp"
#include "rngine/components/text.hpp"
#include <SFML/Graphics.hpp>

namespace RNGine {
class Renderer {
public:
  Renderer(int width, int height, const std::string &title) {
    _window.create(sf::VideoMode(width, height), title);
  }

  void render(RNGine::Registry registry) {
    auto &Sprites = registry.getComponents<RNGine::components::Sprite>();
    auto &Positions = registry.getComponents<RNGine::components::Position>();
    auto &Sizes = registry.getComponents<RNGine::components::Size>();
    auto &Texts = registry.getComponents<RNGine::components::Text>();
    auto entities = Sprites.size();
    _window.clear();
    for (int layer = 0; layer < 5; layer++) {
      for (size_t i = 0; i < entities; i++) {
        auto sprite = Sprites[i];
        if (!sprite.has_value())
          continue;
        auto position = Positions[i];
        if (!position.has_value())
          continue;
        auto size = Sizes[i];
        if (!size.has_value())
          continue;
        if (sprite->layer != layer)
          continue;
        renderSprite(*sprite, *position, *size);
      }
    }
    for (size_t i = 0; i < Texts.size(); i++) {
      std::cout << "Text :" << Texts[i].has_value()
                << ", Pos: " << Positions[i].has_value() << std::endl;
      if (Texts[i].has_value() && Positions[i].has_value()) {
        renderTexte(*Texts[i], *Positions[i]);
      }
    }
    _window.display();
  }
  void renderSprite(RNGine::components::Sprite sprite,
                    RNGine::components::Position position,
                    RNGine::components::Size size) {
    sf::Texture texture;
    if (_textures.find(sprite.path) == _textures.end()) {
      if (!texture.loadFromFile(sprite.path))
        return;
      _textures[sprite.path] = texture;
    } else {
      texture = _textures[sprite.path];
    }
    sf::Sprite Sprite;
    Sprite.setTexture(texture);
    Sprite.setTextureRect(sf::IntRect(sprite.sizeTileX * sprite.tileX,
                                      sprite.sizeTileY * sprite.tileY,
                                      sprite.sizeTileX, sprite.sizeTileY));
    Sprite.setPosition(position.x, position.y);
    double scaleX = size.scaleX;
    if (sprite.reverse)
      scaleX = scaleX * -1;
    Sprite.setScale(scaleX, size.scaleY);
    _window.draw(Sprite);
  }
  void renderTexte(RNGine::components::Text text,
                   RNGine::components::Position position) {
    std::cout << "Try to print text" << std::endl;
    sf::Text Text;
    Text.setString(text.text);
    Text.setFillColor(text.color);
    Text.setCharacterSize(text.CharacterSize);
    Text.setPosition(position.x, position.y);
    _window.draw(Text);
  }

  sf::RenderWindow &getWindow() { return _window; }

private:
  sf::RenderWindow _window = sf::RenderWindow();
  std::map<std::string, sf::Texture> _textures = {};
};
} // namespace RNGine

#endif
