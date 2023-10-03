/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Renderer
*/

#include "Renderer.hpp"

Renderer::Renderer(int width, int height, std::string title)
{
    _window.create(sf::VideoMode(width, height), title);
}

Renderer::~Renderer()
{
}

void Renderer::render(GameEngine::Registry registry)
{
    GameEngine::SparseArray<Sprite> &Sprites = registry.getComponents<Sprite>();
    GameEngine::SparseArray<Position> &Positions = registry.getComponents<Position>();
    GameEngine::SparseArray<Size> &Sizes = registry.getComponents<Size>();
    for (size_t i = 0; i < Sprites.size(); i++)
    {
        try
        {
            auto sprite = Sprites[i];
            auto position = Positions[i];
            auto size = Sizes[i];
            renderSprite(sprite, position, size);
        }
        catch (const std::exception &e)
        {
            continue;
        }
    }
    _window.display();
}

void Renderer::renderSprite(Sprite sprite, Position position, Size size)
{
    sf::Texture texture;
    if (!texture.loadFromFile(sprite.path))
        std::cout << "Texture don't load..." << std::endl;
    sf::Sprite Sprite;
    Sprite.setTexture(texture);
    Sprite.setTextureRect(sf::IntRect(sprite.sizeTileX * sprite.tileX, sprite.sizeTileY * sprite.tileY, sprite.sizeTileX, sprite.sizeTileY));
    Sprite.setPosition(position.x, position.y);
    double scaleX = ((double) size.width) / sprite.sizeTileX;
    double scaleY = ((double) size.height) / sprite.sizeTileY;
    Sprite.setScale(scaleX, scaleY);
    _window.draw(Sprite);
}

sf::RenderWindow &Renderer::getWindow()
{
    return _window;
}