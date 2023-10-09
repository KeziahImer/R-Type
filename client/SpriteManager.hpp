/*
** EPITECH PROJECT, 2023
** poc
** File description:
** spriteManager
*/

#ifndef SPRITEMANAGER_HPP_
#define SPRITEMANAGER_HPP_
#include <SFML/Graphics.hpp>
#include <iostream>

class SpriteManager {
public:
  SpriteManager() = default;

  void loadTexture(const std::string &name, const std::string &filename) {
    sf::Texture texture;
    if (texture.loadFromFile(filename)) {
      textures[name] = texture;
    }
  }

  sf::Sprite createSprite(const std::string &textureName,
                          const sf::Vector2f &position,
                          const sf::Vector2f &scale, const sf::Color &color) {
    sf::Sprite sprite;
    if (textures.find(textureName) != textures.end()) {
      sprite.setTexture(textures[textureName]);
      sprite.setPosition(position);
      sprite.setScale(scale);
      sprite.setColor(color);
    } else
      std::cerr << "Texture " << textureName << " not found." << std::endl;
    return sprite;
  }

private:
  std::map<std::string, sf::Texture> textures;
};

#endif /* !SPRITEMANAGER_HPP_ */
