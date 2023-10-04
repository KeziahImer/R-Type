/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Components
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <utility>

struct Position {
  int x;
  int y;
};

struct Sprite {
  std::string path;
  int sizeTileX;
  int sizeTileY;
  int tileX;
  int tileY;
};

struct Velocity {
  int x;
  int y;
};

struct Movable {
  std::map<enum sf::Keyboard::Key, std::pair<int, int>> keybinds;
};

struct Size {
  int width;
  int height;
};