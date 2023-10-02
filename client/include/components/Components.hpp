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

struct Position
{
    int x;
    int y;
};

struct Sprite
{
    std::string path;
    int sizeTileX;
    int sizeTileY;
    int tileX;
    int tileY;
};

struct Velocity
{
    int x;
    int y;
};

struct Movable
{
    std::map<enum sf::Keyboard::Key, std::pair<int, int>> keybinds;
};

struct Size
{
    int width;
    int height;
};

class Component {
public:
    Component(std::string id = "") : componentID(id) {}
    virtual ~Component() = default;
    std::string getID() const { return componentID; }

private:
    std::string componentID;
};

class PositionComponent : public Component
{
public:
    PositionComponent(std::string id, int x, int y) : Component(id), data{x, y} {}
    Position data;
};

class SpriteComponent : public Component
{
public:
    SpriteComponent(std::string id, const std::string &path, int sizeTileX, int sizeTileY, int tileX, int tileY)
        : Component(id), data{path, sizeTileX, sizeTileY, tileX, tileY} {}
    Sprite data;
};

class VelocityComponent : public Component
{   
public:
    VelocityComponent(std::string id, int x, int y) : Component(id), data{x, y} {}
    Velocity data;
};

class MovableComponent : public Component
{
public:
    MovableComponent(std::string id, const std::map<sf::Keyboard::Key, std::pair<int, int>> &keybinds)
        : Component(id), data{keybinds} {}
    Movable data;
};

class SizeComponent : public Component
{
public:
    SizeComponent(std::string id, int width, int height) : Component(id), data{width, height} {}
    Size data;
};
