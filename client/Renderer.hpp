/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Renderer
*/
#pragma once
#include <SFML/Graphics.hpp>

class Renderer
{
public:
    Renderer(int width, int height, std::string title);
    ~Renderer();

    void render();

private:
    sf::RenderWindow _window;
};
