/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Components
*/

#pragma once
#include <iostream>
#include <map>
#include <utility>
#include <SFML/Graphics.hpp>
#include <chrono>

struct Position
{
    float x;
    float y;
};

struct Sprite
{
    std::string path;
    bool reverse;
    float sizeTileX;
    float sizeTileY;
    int tileX;
    int tileY;
    
};

struct Velocity
{
    float x;
    float y;
};

struct Size
{
    double scaleX;
    double scaleY;
};

struct Movable
{
    std::map<enum sf::Keyboard::Key, std::pair<float, float>> keybinds;
};

struct Shoot
{
    sf::Keyboard::Key Input;
    int speedX;
    bool canShoot;
    int timeMillisecond;
    std::chrono::_V2::system_clock::duration lastShoot;
};

struct parallax
{
    bool parallax;
};