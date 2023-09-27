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
}