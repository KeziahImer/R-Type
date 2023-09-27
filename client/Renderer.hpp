/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Renderer
*/
#pragma once
#include <SFML/Graphics.hpp>
#include "GameEngine/ECS.hpp"
#include "components/Components.hpp"

class Renderer
{
public:
    Renderer(int width, int height, std::string title);
    ~Renderer();

    void render(GameEngine::Registry registry);

private:
    sf::RenderWindow _window;
};
