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
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "rngine/components/Clickable.hpp"
#include "rngine/components/healthBar.hpp"
#include "rngine/components/text.hpp"
#include <SFML/Graphics.hpp>
#include <cstring>

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
    auto &healthBars = registry.getComponents<RNGine::components::healthBar>();
    auto &Buttons = registry.getComponents<RNGine::components::Button>();
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
      if (Texts[i].has_value() && Positions[i].has_value()) {
        renderTexte(*Texts[i], *Positions[i]);
      }
    }
    for (size_t i = 0; i < healthBars.size(); i++) {
      if (healthBars[i].has_value() && Positions[i].has_value() &&
          Sprites[healthBars[i]->entity].has_value() &&
          Sizes[healthBars[i]->entity].has_value()) {
        renderHealth(*healthBars[i], *Positions[i],
                     *Sprites[healthBars[i]->entity],
                     *Sizes[healthBars[i]->entity]);
      }
    }
    for (size_t i = 0; i < Buttons.size(); i++) {
      if (Buttons[i].has_value() && Positions[i].has_value()) {
        renderButton(*Buttons[i], *Positions[i]);
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
    sf::Font font;
    if (_fonts.find(text.font) == _fonts.end()) {
      if (!font.loadFromFile(text.font))
        return;
      _fonts[text.font] = font;
    } else {
      font = _fonts[text.font];
    }
    sf::Text Text;
    Text.setString(text.text + text.text2);
    Text.setFillColor(text.color);
    Text.setCharacterSize(text.CharacterSize);
    Text.setPosition(position.x, position.y);
    Text.setFont(font);
    _window.draw(Text);
  }

  void renderHealth(RNGine::components::healthBar text,
                    RNGine::components::Position position,
                    RNGine::components::Sprite sprite,
                    RNGine::components::Size size) {

    sf::RectangleShape HealthSquare(
        sf::Vector2f(sprite.sizeTileX * size.scaleX, 15));
    sf::RectangleShape Health(sf::Vector2f(
        (text.hp / text.maxHp) * sprite.sizeTileX * size.scaleX - 5, 10));
    HealthSquare.setFillColor(sf::Color::White);
    HealthSquare.setPosition(position.x, position.y);
    Health.setFillColor(text.color);
    Health.setPosition(position.x + 2.5, position.y + 2.5);
    _window.draw(HealthSquare);
    _window.draw(Health);
  }

  void renderButton(RNGine::components::Button button,
                    RNGine::components::Position position) {

    sf::Font font;
    if (_fonts.find(button.font) == _fonts.end()) {
      if (!font.loadFromFile(button.font))
        return;
      _fonts[button.font] = font;
    } else {
      font = _fonts[button.font];
    }
    sf::RectangleShape ButtonSquare(sf::Vector2f(button.x, button.y));
    ButtonSquare.setFillColor(sf::Color::Black);
    ButtonSquare.setOutlineColor(button.color);
    ButtonSquare.setOutlineThickness(5);
    ButtonSquare.setPosition(position.x, position.y);
    sf::Text Text;
    Text.setString(button.buttonText);
    Text.setFillColor(button.color);
    Text.setCharacterSize(button.CharacterSize);
    Text.setPosition(position.x + 15,
                     position.y + (button.y - button.CharacterSize) / 2);
    Text.setFont(font);
    _window.draw(ButtonSquare);
    _window.draw(Text);
  }

  sf::RenderWindow &getWindow() { return _window; }

private:
  sf::RenderWindow _window = sf::RenderWindow();
  std::map<std::string, sf::Texture> _textures = {};
  std::map<std::string, sf::Font> _fonts = {};
};
} // namespace RNGine

#endif
